//
// Created by amit on 12/4/17.
//

#ifndef EX4_NET_GAME_H
#define EX4_NET_GAME_H


#include "GameLogic.h"
#include "Screen.h"
#include "Client.h"
#include "Game.h"

class NetGame : public Game {
public:
    NetGame(GameLogic* logic, Screen* screen, char *fileName);
    ~NetGame();
    virtual void run();
private:
    Board* board;
    GameLogic* logic;
    Screen* screen;
    char *fileName;
};


#endif //EX4_GAME_H
