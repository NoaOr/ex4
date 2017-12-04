/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */

#include <map>
#include "AIPlayer.h"

AIPlayer :: AIPlayer(Cell :: Value value, GameLogic* logic) {
    this ->value = value;
    this->logic = logic;
    this->hasMove = true;
}
Cell ::Value AIPlayer :: getVal() const {
    return this->value;
}

bool AIPlayer ::hasMoreMoves() {
    return this->hasMove;
}

Coordinate AIPlayer :: doYourTurn(Board *board, Screen *screen) {
    list<Coordinate> optionsList = getOptionsList(board);
    list<Coordinate> :: const_iterator listIter;
    int m, min = 0;
    Cell c(Cell::Empty);
    map<int, Coordinate> optionsMap;
    for (listIter = optionsList.begin(); listIter != optionsList.end(); ++listIter) {
        Board *tempBoard = new Board(*board);
        Coordinate optionCoor(listIter->getRow() + 1, listIter->getCol() + 1);
        tempBoard->updateBoard(optionCoor, this->value);
        m = bestOpponentChoice(tempBoard, c.getOpponentVal(this->value));
        optionsMap[m] = *listIter;
        delete(tempBoard);
    }

    if (optionsMap.empty()) {
        movePasses(screen, this->valueToChar(this->value));
        return Coordinate(-1,-1);
    }
    map<int, Coordinate> :: const_iterator mapIter;

    for (mapIter = optionsMap.begin(); mapIter != optionsMap.end(); mapIter++) {
        if (mapIter == optionsMap.begin()) {
            min = mapIter->first;
        }
        if (mapIter->first <= min) {
            min = mapIter->first;
        }
    }
    Coordinate best(optionsMap[min].getRow() + 1, optionsMap[min].getCol() + 1);
    return best;

}

list<Coordinate> AIPlayer :: getOptionsList(Board *board) {
    list<Coordinate> optionsList;
    int row = board->getRowSize(), col = board->getColSize();
    for (int i = row; i >= 0; i--) {
        for (int j = col; j >= 0 ; j--) {
            Coordinate coor = Coordinate(i, j);
            if (!this->logic->findOptions(coor, this->value, board).empty()
                && board->getCellAt(coor)->getValue() == Cell :: Empty) {
                optionsList.push_back(coor);
            }
        }
    }
    return optionsList;
}

int AIPlayer :: bestOpponentChoice(Board *board, Cell::Value opponentVal) {
    int max = 0;
    int listSize;
    for (int i = 0; i < board->getRowSize(); i++) {
        for (int j = 0; j < board->getColSize(); j++) {
            Coordinate coor = Coordinate(i, j);
            // listSize is the number of cells that should have been
            // fliped if the opponent chose the coordinate.
            listSize = (int) this->logic->findOptions(coor, opponentVal, board).size();
            if (listSize > max) {
                max = listSize;
            }
        }
    }
    return max;
}

void AIPlayer ::movePasses(Screen *screen, char value) {
    this->hasMove = false;
    screen->showMovePasses(this->getVal());
}

void AIPlayer::showChoice(Coordinate c, Screen *screen) const {

    screen->showPlayersChoice(this->getVal(), c);

}