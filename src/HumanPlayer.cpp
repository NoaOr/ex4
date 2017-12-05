/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */
#include <list>
#include <limits>
#include "HumanPlayer.h"
#include "Screen.h"
HumanPlayer ::HumanPlayer(Cell::Value value, GameLogic *logic) {
    this ->value = value;
    this->logic = logic;
    this->hasMove = true;
}
Coordinate HumanPlayer ::doYourTurn(Board *board, Screen *screen) {
    list<Coordinate> optionsList;
    int row = board->getRowSize(), col = board->getColSize();
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            Coordinate coor = Coordinate(i, j);

            if (!this->logic->findOptions(coor, this->value, board).empty()
                    && board->getCellAt(coor)->getValue() == Cell :: Empty) {
                optionsList.push_back(coor);
            }
        }
    }
    char stringVal;
    if (this->value == Cell :: X) {
        stringVal = 'X';
    } else {
        stringVal = 'O';
    }

    if (!optionsList.empty()) {
        this->hasMove = true;
        screen->showOptions(optionsList, stringVal);
        Coordinate choice = this->getChoice(optionsList, screen);
        return choice;
    } else {
        movePasses(screen, stringVal);
    }


}

Coordinate HumanPlayer ::getChoice(list<Coordinate> optionsList, Screen *screen) const {
    list<Coordinate> ::const_iterator listIterator;
        bool isInList = false;
        int num1 = -1, num2 = -1;
        cin >> num1 >> num2;
        if (!num1 || !num2) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        Coordinate choice = Coordinate(num1, num2);
        for (listIterator = optionsList.begin();
             listIterator != optionsList.end(); ++listIterator) {
            if (num1 == listIterator->getRow() + 1
                && num2 == listIterator ->getCol() + 1) {
                isInList = true;
                choice = Coordinate(num1, num2);
                break;
            }
        }
        if (!isInList) {
            screen->showUnValidMove();
            choice = this ->getChoice(optionsList, screen);
        }

    return choice;
}
Cell ::Value HumanPlayer :: getVal() const {
    return this->value;
}

bool HumanPlayer ::hasMoreMoves() {
    return this->hasMove;
}

void HumanPlayer::movePasses(Screen *screen, char value) {
    this->hasMove = false;
    screen->showMovePasses(this->getVal());


}

void HumanPlayer:: showChoice(Coordinate c, Screen *screen) const {}