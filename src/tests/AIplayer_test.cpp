 #include "AIplayer_test.h"
#include "../Board.h"
#include "../RegularLogic.h"
#include "../AIPlayer.h"
#include "../ConsoleScreen.h"

 AIplayer_test :: AIplayer_test (){}
void AIplayer_test :: SetUp() {}
void AIplayer_test :: TearDown() {}
// the function checks if the AIPlayer chose the expected choice.
TEST_F(AIplayer_test, expectedChoice) {
    RegularLogic r;
     ConsoleScreen screen;
    Board board(8, 8, &r);
    AIPlayer player(Cell::O, &r);
    Coordinate choice;

    board.updateBoard(Coordinate(3, 4), Cell::X);
    choice = player.doYourTurn(&board, &screen);
    EXPECT_EQ(choice, Coordinate(3, 3));
}
// the function checks if the AIplayer can handle the case he has only one move.
TEST_F(AIplayer_test, oneOptionToAIPlayer) {
    RegularLogic r;
    ConsoleScreen screen;
    Board board(8, 8, &r);
    AIPlayer player(Cell::O, &r);
    Coordinate choice;

   board.updateCell(0, 0, Cell::O);
    for (int i = 1; i < 4; i++) {
        board.updateCell(i, 0, Cell::X);
    }
    for (int i = 0; i < 3; i++) {
        board.updateCell(i, 1, Cell::X);
    }
    board.updateCell(1, 2, Cell::X);
    board.updateCell(2, 2, Cell::O);
    //the current board:
    //     | 1 | 2 | 3 | 4 |
    //      ------------------
    //      1| O | X |   |   |
    //      ------------------
    //      2| X | X | X |   |
    //      ------------------
    //      3| X | X | O |   |
    //      ------------------
    //      4| X |   |   |   |
    //      -----------------
    //  AI Player has one option to choose - (1, 3)

    choice = player.doYourTurn(&board, &screen);
    EXPECT_EQ(choice, Coordinate(1, 3));
}
