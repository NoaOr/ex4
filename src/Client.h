//
// Created by amit on 12/4/17.
//

#ifndef EX4_CLIENT_H
#define EX4_CLIENT_H


#include "HumanPlayer.h"
#include "Screen.h"

class Client {
public:
    Client(const char *serverIP, int serverPort,
           GameLogic* gameLogic, Board* board, Screen *screen);
    void connectToServer();
    bool sendChoice();
    bool readOpponentChoice();
    bool readMassage();
    bool isNoMoveMsg(int *buffer);
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    HumanPlayer player;
    Board* board;
    GameLogic* gameLogic;
    Screen* screen;
};


#endif //EX4_CLIENT_H
