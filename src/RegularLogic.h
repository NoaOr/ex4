/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */
#ifndef EX2_REGULARLOGIC_H
#define EX2_REGULARLOGIC_H

#include "GameLogic.h"
#include "Cell.h"
#include "Coordinate.h"
#include "Board.h"
class RegularLogic: public GameLogic {
public:
    /**
     * constructor
     */
    RegularLogic();
    /**
     *
     * @return boolean
     */
    bool isRegularRules() const;
/**
 * THe function finds options of cells to the current pkayer.
 * @param c - the coordinate to check.
 * @param v - the current player's value.
 * @param board - the board.
 * @return - list of coordinates to flip.
 */
    list<Coordinate> findOptions(Coordinate coor,Cell::Value, Board *board) const;
    /**
     *
     * @param coor
     * @param board
     * @return
     */
    bool isOnBoard(Coordinate coor, Board *board) const;

private:
    bool isRegular;
};


#endif //EX2_REGULARLOGIC_H
