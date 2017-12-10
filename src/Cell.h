/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */
#ifndef EX1_CELL_H
#define EX1_CELL_H

#include<iostream>
using namespace std;


class Cell {
public:
    enum Value {X, O, Empty};
    /**
     * constructor
     * @param value - the value of the cell.
     */
    Cell(Value value);
    /**
     *
     * @return the value of the cell.
     */
    Cell :: Value getValue() const;
    /**
     *
     * @param newValue sets the cell's value
     * to be the received value.
     */
    void setValue(Cell :: Value newValue);
    /**
     *
     * @param value - the value of the current player
     * @return - the value of the opponent player.
     */
    Cell::Value getOpponentVal(Cell::Value value);
    /**
     * destructor
     */
    ~Cell();

    /**
     *
     * @return the char of the value.
     */
    char valueToChar() const;
private:
    Cell :: Value value;
};


#endif //EX1_CELL_H
