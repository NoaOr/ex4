/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */
#include <map>
#include <list>
#include "RegularLogic.h"



RegularLogic ::RegularLogic() {
    this->isRegular = true;
}
/**
 *
 * @param coor
 * @param value
 * @param board
 * @return the list of cells that need to be fliped
 */
list<Coordinate> RegularLogic :: findOptions(Coordinate coor,
                                             Cell::Value value, Board *board) const {

    Cell :: Value otherVal;
    Cell :: Value myVal = value;
    list<Coordinate> cellsToFlip;
    if (myVal == Cell ::X) {
        otherVal = Cell ::O;
    } else {
        otherVal = Cell ::X;
    }
    // if the point is not on the board return empty list.
    if(!this->isOnBoard(coor, board)) {
        //return nullptr;
        return list<Coordinate>();
    }
    int startX = coor.getRow();
    int startY = coor.getCol();
    list<Coordinate> directions;
    directions.push_back(Coordinate(0,1));
    directions.push_back(Coordinate(0,-1));
    directions.push_back(Coordinate(1,1));
    directions.push_back(Coordinate(1,-1));
    directions.push_back(Coordinate(1,0));
    directions.push_back(Coordinate(-1,-1));
    directions.push_back(Coordinate(-1,0));
    directions.push_back(Coordinate(-1,1));
    list<Coordinate> ::const_iterator iter;

    for (iter = directions.begin(); iter != directions.end(); ++iter) {
        int x = startX, y = startY;
        // advance the coordinate to the direction that in the list:
        x += iter->getRow();
        y += iter->getCol();
        Coordinate c = Coordinate(x, y);

        // if the cell on the board and the value is not my value:
        // advance the cell in the same direction
        if (isOnBoard(c, board) && board->getCellAt(c)->getValue() == otherVal) {
            x += iter->getRow();
            y += iter->getCol();
            c = Coordinate(x, y);

            if (!isOnBoard(c, board)) {
                continue;
            }

            if (board->getCellAt(c)->getValue() == myVal) {
                x -= iter->getRow();
                y -= iter->getCol();
                Coordinate coordinate = Coordinate(x, y);
                cellsToFlip.push_back(coordinate);
                x += iter->getRow();
                y += iter->getCol();
            }
                while (board->getCellAt(c)->getValue() == otherVal) {
                    x += iter->getRow();
                    y += iter->getCol();
                    c = Coordinate(x, y);
                    if (!isOnBoard(c, board)) {
                        break;
                    }
                }

                if (isOnBoard(c, board)) {
                    if (board->getCellAt(c)->getValue() == myVal) {
                        while (x != startX || y != startY) {
                            x -= iter->getRow();
                            y -= iter->getCol();
                            c = Coordinate(x, y);
                            cellsToFlip.push_back(c);
                        }
                    }
                }
            }

        }
    if (cellsToFlip.size() == 0) {
        return list<Coordinate>();
    }
    return cellsToFlip;


}
bool RegularLogic ::isRegularRules() const {
    return this->isRegular;
}


bool RegularLogic :: isOnBoard(Coordinate coor, Board *board) const{
    int y = coor.getCol(), x = coor.getRow();
    int colSize = board->getColSize() - 1, rowSize = board->getRowSize() - 1;
    return (x >= 0 && x <= rowSize && y >= 0 && y <= colSize);
}
