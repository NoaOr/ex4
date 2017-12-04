cmake_minimum_required(VERSION 3.8)
project(ex4)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES src/main.cpp src/Board.cpp src/Cell.cpp
        src/Coordinate.cpp src/HumanPlayer.cpp src/Player.cpp src/GameLogic.cpp src/RegularLogic.cpp
        src/RegularLogic.h src/GameFlow.cpp src/GameFlow.h src/Screen.cpp src/Screen.h src/ConsoleScreen.cpp
        src/ConsoleScreen.h src/AIPlayer.cpp src/AIPlayer.h src/tests/Board_test.cpp src/tests/Board_test.h
        src/tests/gtest_main.cpp src/tests/gtest_main.h src/tests/logic_test.cpp src/tests/logic_test.h
        src/tests/AIplayer_test.cpp src/tests/AIplayer_test.h)

add_executable(ex4 ${SOURCE_FILES})
target_link_libraries(ex4 gtest gtest_main gmock)








#set(SOURCE_FILES main.cpp tests/DriverLocationTest.cpp
#        tests/TaxiCenterTest.cpp tests/PassengerTest.cpp
#        tests/PointTest.cpp tests/NodeTest.cpp tests/ObstacleTest.cpp tests/TripInfoTest.cpp tests/LuxaryTaxiTest.cpp tests/BasicTaxiTest.cpp tests/GridTest.cpp tests/BFSTest.cpp tests/FlowManagerTest.cpp tests/InputParserTest.cpp)

#add_test(runUnitTests runUnitTests)
