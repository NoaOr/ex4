//
// Created by amit on 11/21/17.
//

#include "Board_test.h"

Board_test :: Board_test (){}
void Board_test :: SetUp(){}
void Board_test ::TearDown(){}
// the function checks if the board updates the board as expected.
TEST_F(Board_test, checkUpdateBoard) {
    RegularLogic r;
    Board firstBoard(8, 8, &r);
    Board updatedBoard(8, 8, &r);

    firstBoard.updateBoard(Coordinate(3, 4) , Cell::X);
    updatedBoard.updateCell(2, 3, Cell::X);
    updatedBoard.updateCell(3, 3, Cell::X);
    EXPECT_EQ(firstBoard, updatedBoard);
    firstBoard.updateBoard(Coordinate(3, 3), Cell::O);
    updatedBoard.updateCell(2, 2, Cell::O);
    updatedBoard.updateCell(3, 3, Cell::O);
    EXPECT_EQ(firstBoard, updatedBoard);
}
// the function checks if the board updates the board as expected in the last turn.
TEST_F(Board_test, updateLastTurn) {
    RegularLogic r;
    Board board(4, 4, &r);
    board.updateBoard(Coordinate(1, 2), Cell::X);
    board.updateBoard(Coordinate(1, 1), Cell::O);
    board.updateBoard(Coordinate(2, 1), Cell::X);
    board.updateBoard(Coordinate(1, 3), Cell::O);
    board.updateBoard(Coordinate(1, 4), Cell::X);
    board.updateBoard(Coordinate(3, 1), Cell::O);
    board.updateBoard(Coordinate(4, 1), Cell::X);
    board.updateBoard(Coordinate(2, 4), Cell::O);
    board.updateBoard(Coordinate(3, 4), Cell::X);
    board.updateBoard(Coordinate(4, 2), Cell::O);
    board.updateBoard(Coordinate(4, 3), Cell::X);

    EXPECT_EQ(board.getCellAt(Coordinate(3, 3))->getValue(), Cell::Empty);
    board.updateBoard(Coordinate(4,4), Cell::O);

    EXPECT_EQ(board.getCellAt(Coordinate(3, 3))->getValue(), Cell::O);

}