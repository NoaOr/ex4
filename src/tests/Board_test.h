//
// Created by amit on 11/21/17.
//

#ifndef EX3_BOARD_TEST_H
#define EX3_BOARD_TEST_H
#include "../../gtest_src/gtest.h"
#include "../Board.h"
#include "../RegularLogic.h"
#include <iostream>
using namespace std;

    class Board_test : public testing::Test {

    public:
        Board_test ();
        virtual void SetUp();
        virtual void TearDown();
    };

#endif //EX3_BOARD_TEST_H
