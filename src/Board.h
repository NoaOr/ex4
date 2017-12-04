/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */
#ifndef EX2_BOARD_H
#define EX2_BOARD_H

#include <iostream>
#include "Cell.h"
#include "Coordinate.h"
#include "GameLogic.h"
class GameLogic;
using namespace std;

class Board {
public:
/**
 * constructor
 * @param rowSize - number of rows.
 * @param colSize - number od columns.
 * @param logic - the logic of the game.
 */
    Board(int rowSize, int colSize, GameLogic *logic);

    /**
     * Copy Constructor.
     * @param b - the board that should be copied.
     */
    Board(Board &b);

/**
 * this function needs to flip all the cells in the
 * list and show the board again.
 * @param coordinate - the player's choice.
 * @param changedTo - the player's value.
 */
    void updateBoard(Coordinate coordinate, Cell :: Value changedTo);
/**
 *
 * @return number of columns.
 */
    int getColSize();
/**
 *
 * @return number of rows.
 */
    int getRowSize();

/**
 *
 * @param coor - the coordinate.
 * @return the board in the requested
 */
    Cell* getCellAt(Coordinate coor);
    /**
     * destructor
     */
    ~Board();
    /**
     * The function implements the "==" operator.
     * @param board - a board to be compared.
     * @return boolean - if the boards are equal, it is true.
     */
    bool operator==(const Board &board)const;
    /**
     * The function updates the cell's value.
     * @param x - the x coordinate.
     * @param y - the y coordinate.
     * @param value - the new value.
     */
    void updateCell(int x, int y, Cell::Value value);
private:
    Cell*** boardTable;
    int rowSize;
    int colSize;
    GameLogic *gameLogic;
};


#endif //EX2_BOARD_H
