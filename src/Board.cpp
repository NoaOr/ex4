/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */
#include <list>
#include "Board.h"
/**
 * constructor
 * @param rowSize - number of rows.
 * @param colSize - number od columns.
 * @param logic - the logic of the game.
 */
Board :: Board(int rowSize, int colSize, GameLogic *logic) {
    this -> gameLogic = logic;
    this -> rowSize = rowSize;
    this -> colSize = colSize;
    this -> boardTable = new Cell**[rowSize];

    // for every cell in the row, make new column of cells.
    for (int i = 0; i < rowSize; i++) {
        this -> boardTable[i] = new Cell*[colSize];
    }
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            this -> boardTable[i][j] = new Cell(Cell::Empty);
        }
    }

    int midRow = rowSize / 2 - 1;
    int midCol = colSize / 2 - 1;
    this -> boardTable[midRow][midCol] -> setValue(Cell :: O);
    this -> boardTable[midRow + 1][midCol + 1] -> setValue(Cell :: O);
    this -> boardTable[midRow][midCol + 1] -> setValue(Cell :: X);
    this -> boardTable[midRow + 1][midCol] -> setValue(Cell :: X);


}

Board ::Board(Board &old_board) {
    this->gameLogic = old_board.gameLogic;
    this->rowSize = old_board.rowSize;
    this->colSize = old_board.colSize;
    this->boardTable = new Cell**[rowSize];

    // for every cell in the row, make new column of cells.
    for (int i = 0; i < rowSize; i++) {
        this -> boardTable[i] = new Cell*[colSize];
    }
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            this -> boardTable[i][j] =
                    new Cell(old_board.getCellAt(Coordinate(i, j))->getValue());
        }
    }

}

/**
 * this function needs to flip all the cells in the
 * list and show the board again.
 * @param coordinate - the player's choice.
 * @param changedTo - the player's value.
 */
void Board ::updateBoard(Coordinate coordinate, Cell::Value changedTo) {
    int row = coordinate.getRow()-1;
    int col = coordinate.getCol()-1;
    this->boardTable[row][col]->setValue(changedTo);
    Coordinate coor = Coordinate(row, col);
    list<Coordinate> cellsToFlip;
    cellsToFlip =
            this->gameLogic->findOptions(coor, changedTo, this);
    list<Coordinate> ::iterator iter;
    for (iter = cellsToFlip.begin(); iter != cellsToFlip.end(); ++iter) {
        int x = iter->getRow(), y = iter->getCol();
            this->boardTable[x][y]->setValue(changedTo);
    }
}
/**
 *
 * @return number of columns.
 */
int Board::getColSize() {
    return this->colSize;
}
/**
 *
 * @return number of rows.
 */
int Board::getRowSize() {
    return this->rowSize;
}
/**
 *
 * @param coor - the coordinate.
 * @return the board in the requested
 */
Cell* Board ::getCellAt(Coordinate coor) {
    int x = coor.getRow();
    int y = coor.getCol();
    Cell *c = this ->boardTable[x][y];
    return c;
}
Board ::~Board() {
    for (int i = 0; i < rowSize; i++) {
        for (int j = 0; j < colSize; j++) {
            delete(boardTable[i][j]);
        }
    }
    for (int i = 0; i < rowSize; i++) {
        delete(boardTable[i]);
    }
    delete(boardTable);
}

bool Board :: operator==(const Board &board) const {
    if (this->colSize != board.colSize || this->rowSize != board.rowSize) {
        return false;
    }
    for(int i = 0; i < this->rowSize; i++) {
        for(int j = 0; j < this->colSize; j++) {
            if(this->boardTable[i][j]->getValue() != board.boardTable[i][j]->getValue()) {
                return false;
            }
        }
    }
    return true;
}

void Board :: updateCell(int x, int y, Cell::Value value) {
    this->boardTable[x][y]->setValue(value);
}