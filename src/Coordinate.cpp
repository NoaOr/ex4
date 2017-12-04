/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */
#include "Coordinate.h"

Coordinate ::Coordinate(int row, int col) {
    this->row = row;
    this->col = col;
}
Coordinate ::Coordinate() {}
int Coordinate ::getCol() const {
    return this ->col;
}
int Coordinate ::getRow() const {
    return this -> row;
}
bool Coordinate :: operator==(const Coordinate &coordinate) const {
    return this->row == coordinate.row && this->col == coordinate.col;
}