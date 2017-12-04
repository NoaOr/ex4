//
// Created by amit on 11/25/17.
//

#include "logic_test.h"
logic_test ::logic_test() {}
void logic_test ::SetUp() {}
void logic_test ::TearDown() {}
// check what happens if there are no options
TEST_F(logic_test, noOptions){
    RegularLogic logic;
    Board b(8, 8, &logic);
    b.updateBoard(Coordinate(3,4), Cell::X);
    b.updateBoard(Coordinate(3,3), Cell::O);
    b.updateBoard(Coordinate(3,2), Cell::X);
    b.updateBoard(Coordinate(2,2), Cell::O);
    b.updateBoard(Coordinate(1,2), Cell::X);
    b.updateBoard(Coordinate(1,1), Cell::O);
    b.updateBoard(Coordinate(4,3), Cell::X);
    b.updateBoard(Coordinate(1,3), Cell::O);
    b.updateBoard(Coordinate(2,3), Cell::X);
    b.updateBoard(Coordinate(2,4), Cell::O);
    b.updateBoard(Coordinate(1,4), Cell::X);
    b.updateBoard(Coordinate(1,5), Cell::O);
    b.updateBoard(Coordinate(2,1), Cell::X);
    b.updateBoard(Coordinate(3,1), Cell::O);
    b.updateBoard(Coordinate(5,6), Cell::X);
    b.updateBoard(Coordinate(2,5), Cell::O);
    b.updateBoard(Coordinate(1,6), Cell::X);
    b.updateBoard(Coordinate(1,7), Cell::O);

    list<Coordinate> options;
    for (int i = 0; i < b.getRowSize(); i++) {
        for (int j = 0; j < b.getColSize(); j++) {
            Coordinate c = Coordinate(i, j);

            if (!logic.findOptions(c, Cell::X, &b).empty()
                && b.getCellAt(c)->getValue() == Cell :: Empty) {
                options.push_back(c);
            }
        }
    }

    EXPECT_EQ(options.size(), 0);
}
// check what happens if there is one option.
TEST_F(logic_test, oneOption) {
    RegularLogic logic;
    Board b(4, 4, &logic);
    int options = 0;
    list<Coordinate> listOptionsToFlip;
    list<Coordinate> listOptions;
    list<Coordinate> :: const_iterator listIter;
    b.updateCell(0, 0, Cell::O);
    for (int i = 1; i < 4; i++) {
        b.updateCell(i, 0, Cell::X);
    }
    for (int i = 0; i < 3; i++) {
        b.updateCell(i, 1, Cell::X);
    }
    b.updateCell(1, 2, Cell::X);
    b.updateCell(2, 2, Cell::O);
    for(int i = 0; i < b.getRowSize(); i++) {
        for (int j = 0; j < b.getColSize(); j++) {
            listOptionsToFlip = logic.findOptions(Coordinate(i, j), Cell::O, &b);
            if(b.getCellAt(Coordinate(i,j))->getValue() == Cell::Empty &&
                    listOptionsToFlip.size() != 0) {
                options++;
                Coordinate c(i, j);
                listOptions.push_back(c);
            }
        }
    }
    EXPECT_EQ(options, 1);
    listIter = listOptions.begin();
    EXPECT_EQ(*listIter, Coordinate(0, 2));
}
// checks an empty board.
TEST_F(logic_test, emptyBoard) {
    RegularLogic logic;
    Board b(8,8,&logic);
    list<Coordinate> optionsForX;
    bool first = false, second = false, third = false, fourth = false;
    for (int i = 0; i < b.getRowSize(); i++) {
        for (int j = 0; j < b.getColSize(); j++) {
            Coordinate c(i, j);
            if (!logic.findOptions(c, Cell::X, &b).empty()
                && b.getCellAt(c)->getValue() == Cell :: Empty) {
                optionsForX.push_back(c);
            }
        }
    }
    EXPECT_EQ(optionsForX.size(), 4);
    list<Coordinate> ::const_iterator iter;
    // the coordinate here are represented as the indexes in the computer
    // for example, (2,3) is represented to the player as (3,4)
    for (iter = optionsForX.begin(); iter != optionsForX.end(); ++iter) {
        if (*iter == Coordinate(2,3)) {
            first = true;
        } else if (*iter == Coordinate(3,2)) {
            second = true;
        } else if (*iter == Coordinate(4,5)){
            third = true;
        } else if (*iter == Coordinate(5,4)) {
            fourth = true;
        }
    }

    EXPECT_TRUE(first);
    EXPECT_TRUE(second);
    EXPECT_TRUE(third);
    EXPECT_TRUE(fourth);

}

// the function checks the logic with several coordinates.
TEST_F(logic_test, severalCoordinates) {
    RegularLogic logic;
    Board b(4,4, &logic);
    b.updateBoard(Coordinate(1,2), Cell::X);
    b.updateBoard(Coordinate(1,3), Cell::O);
    b.updateBoard(Coordinate(3,4), Cell::X);
    list<Coordinate> optionsForO;
    bool first = false, second = false, third = false;
    for (int i = 0; i < b.getRowSize(); i++) {
        for (int j = 0; j < b.getColSize(); j++) {
            Coordinate c(i, j);
            if (!logic.findOptions(c, Cell::O, &b).empty()
                && b.getCellAt(c)->getValue() == Cell :: Empty) {
                optionsForO.push_back(c);
            }
        }
    }
    EXPECT_EQ(optionsForO.size(), 3);
    list<Coordinate> ::const_iterator iter;
    // the coordinate here are represented as the indexes in the computer
    // for example, (0,0) is represented to the player as (1,1)
    for (iter = optionsForO.begin(); iter != optionsForO.end(); ++iter) {
        if (*iter == Coordinate(0,0)) {
            first = true;
        } else if (*iter == Coordinate(2,0)) {
            second = true;
        } else if (*iter == Coordinate(3,2)) {
            third = true;
        }
    }

    EXPECT_TRUE(first);
    EXPECT_TRUE(second);
    EXPECT_TRUE(third);

}