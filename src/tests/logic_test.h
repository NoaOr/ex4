//
// Created by amit on 11/25/17.
//

#ifndef EX3_LOGIC_TEST_H
#define EX3_LOGIC_TEST_H
#include "../../gtest_src/gtest.h"
#include "../Board.h"
#include "../RegularLogic.h"
#include <iostream>
using namespace std;

class logic_test : public testing::Test  {

public:

public:
    logic_test ();
    virtual void SetUp();
    virtual void TearDown();
};



#endif //EX3_LOGIC_TEST_H
