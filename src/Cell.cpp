/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */

#include "Cell.h"
//static enum Value {X = "X", O = "O", Empty = " "};
Cell :: Cell(Cell :: Value value) {
    this->value = value;
}


Cell :: Value Cell :: getValue() const {
    return this->value;
}

void Cell :: setValue(Cell :: Value newValue) {
    this->value = newValue;
}

Cell::Value Cell ::getOpponentVal(Cell::Value value) {
    if (value == Cell::X) {
        return Cell::O;
    } else if (value == Cell::O) {
        return Cell::X;
    } else {
        return Cell::Empty;
    }
}
Cell :: ~Cell() {}

char Cell::valueToChar() const {
    if (this->value == Cell::O) {
        return 'O';
    } else if (this->value == Cell::X){
        return 'X';
    }
    return ' ';
}