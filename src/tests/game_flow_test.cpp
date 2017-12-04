//
// Created by noa on 27/11/17.
//

#include "game_flow_test.h"
#include "../Board.h"
#include "../RegularLogic.h"
#include "../GameFlow.h"
#include "../AIPlayer.h"
#include "../ConsoleScreen.h"

game_flow_test::game_flow_test(){}
void game_flow_test::SetUp() {}
void game_flow_test::TearDown() {}
// the function checks that the board is full.
TEST_F(game_flow_test, fullBoard) {
    RegularLogic logic;
    ConsoleScreen screen;
    AIPlayer p1(Cell::X, &logic);
    AIPlayer p2(Cell::O, &logic);
    Board b(2,2,&logic);
    GameFlow game(&logic, &p1, &p2, &screen);
    EXPECT_TRUE(game.isBoardFull());

}