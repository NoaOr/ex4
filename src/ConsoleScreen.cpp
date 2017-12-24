/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */

#include <bitset>
#include <string>
#include <cstring>
#include "ConsoleScreen.h"

#define MAX_SIZE 100
void ConsoleScreen::showBoard(Board *board) {
    cout << '\n' << "current board:" << endl;
    for (int i = 0; i < board->getColSize(); i++) {
        cout << " | " << i + 1;
    }
    cout << " | " << '\n';
    for (int i = 0; i < (board->getColSize() * 4 + 2); i++) {
        cout << "-";
    }

    for (int i = 0; i < board->getRowSize(); i++) {
        cout << '\n';
        cout << i + 1 << "|";
        for (int j = 0; j < board->getColSize(); j++) {
            if (j == 0) {
                cout << " ";
            }
            cout << board->getCellAt(Coordinate(i, j))->valueToChar();
            cout << " | ";
        }
        cout << '\n';
        for (int j = 0; j < (board->getColSize() * 4 + 2); j++) {
            cout << '-';
        }
    }
    cout << '\n' << endl;
}
void ConsoleScreen :: gameOverScreen(Board *board) {

    int numOfX = 0, numOfO = 0;
    for (int i = 0; i < board->getRowSize(); i++) {
        for (int j = 0; j < board->getColSize(); j++) {
            if (board->getCellAt(Coordinate(i, j))->getValue()
                == Cell ::X) {
                numOfX++;
            } else if (board->getCellAt(Coordinate(i, j))->getValue()
                       == Cell ::O) {
                numOfO++;
            }
        }
    }
    cout << '\n' << "The game is over" << endl;
    if (numOfO > numOfX) {
        cout << "The winner is O!" << endl;
    } else if (numOfX > numOfO) {
        cout << "The winner is X!" << endl;
    } else {
        cout << "It's a TIE!" << endl;
    }

}

void ConsoleScreen::showPlayersChoice(Cell::Value val, Coordinate c) {
    char value = 'O';
    if (val == Cell::X) {
        value = 'X';
    }
    cout << value << " chose: (" << c.getRow() << ", " <<
         c.getCol() << ")" << endl;
}

void ConsoleScreen::showMovePasses(Cell::Value val) const {
    char value = 'X';
    char otherVal = 'O';
    if (val == Cell::O) {
        value = 'O';
        otherVal = 'X';
    }
//    cout << '\n' << value << ": It's your move" << endl;
    cout << '\n' << "It's " << value << " move." << endl;
    cout << value << " has no moves. It is " << otherVal << " turn." << endl;
}
void ConsoleScreen :: showUnValidMove() const {
    cout << "Your choice is not valid."
            "Please make another choice.";
}

void ConsoleScreen ::showOptions(list<Coordinate> optionsList, char value) const {
    cout << '\n' << "It's " << value << " move." << endl;
    cout << "Your possible moves:";
    list<Coordinate>::const_iterator listIterator;
    for (listIterator = optionsList.begin();
         listIterator != optionsList.end(); ++listIterator) {
        if (!(listIterator == optionsList.begin())) {
            cout << ", ";
        }
        int x = listIterator->getRow() + 1, y = listIterator->getCol() + 1;
        cout << "(" << x << "," << y << ")";
    }
    cout << '\n' << "Please enter your move row, col:";
}
int ConsoleScreen::menu() const {
    cout << "Hello!" << '\n' << "Choose how to play othello:" << '\n' <<
         "1: 2 Human players." << '\n' <<
         "2: A Human player and an AI player." << endl <<
         "3: A remote player" << endl;
    int choice;
    cin >> choice;
    return choice;
}

void ConsoleScreen::showMessage(string msg) const {
    cout << msg << endl;
}

void ConsoleScreen::showMessage(char msg[], int msgSize) const {
    string str (msg);
    cout <<str<< endl;
}

void ConsoleScreen::opponentHasNoMove() const {
    cout << "Your opponent has no move. It's your turn." << endl;
}

const char* ConsoleScreen::scanFromUser() {
//    char choice [MAX_SIZE];
    string choice;
//    cin >> choice;
    cin.ignore();
    std::getline(cin, choice);
    const char * s = choice.c_str();
    return s;
}