/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */

#include "Player.h"

char Player::valueToChar(Cell::Value val) const {
    if (val == Cell::O) {
        return 'O';
    } else if (val == Cell::X){
        return 'X';
    }
    return ' ';
}