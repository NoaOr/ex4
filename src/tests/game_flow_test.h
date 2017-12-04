//
// Created by noa on 27/11/17.
//

#include <iostream>
#include "../../gtest_src/gtest.h"
#ifndef EX3_GAME_FLOW_TEST_H
#define EX3_GAME_FLOW_TEST_H

using namespace std;

class game_flow_test : public testing::Test {

public:
    game_flow_test();
    virtual void SetUp();
    virtual void TearDown();
};



#endif //EX3_GAME_FLOW_TEST_H
