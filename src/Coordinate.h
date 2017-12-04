/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */

#ifndef EX2_COORDINATE_H
#define EX2_COORDINATE_H


class Coordinate {
public:
    /**
     * Constructor
     * @param row - row size.
     * @param col - col size.
     */
    Coordinate(int row, int col);
    /**
     * Constructor.
     */
    Coordinate();
    /**
     *
     * @return row member.
     */
    int getRow() const;
    /**
     *
     * @return col member.
     */
    int getCol() const;
    /**
     * The function implements the "==" operator.
     * @param coordinate -another coordinate.
     * @return true if the coordinates are equal, and false otherwise.
     */
    bool operator==(const Coordinate &coordinate) const;
private:
    int row;
    int col;
};


#endif //EX2_COORDINATE_H
