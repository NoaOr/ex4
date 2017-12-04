/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */

#ifndef EX2_GAMELOGIC_H
#define EX2_GAMELOGIC_H

#include <list>
#include "Board.h"
#include "Cell.h"
#include "Coordinate.h"
class Board;
class GameLogic {
public:
/**
 * THe function finds options of cells to the current pkayer.
 * @param c - the coordinate to check.
 * @param v - the current player's value.
 * @param board - the board.
 * @return - list of coordinates to flip.
 */
    virtual list<Coordinate> findOptions(Coordinate c,
                                         Cell::Value v, Board *board) const = 0;
    virtual bool isRegularRules() const = 0;

private:
    bool isRegular;
};


#endif //EX2_GAMELOGIC_H
