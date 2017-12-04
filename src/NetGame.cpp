//
// Created by amit on 12/4/17.
//

#include "NetGame.h"
#define BOARD_SIZE 8
NetGame::NetGame(GameLogic* logic, Screen* screen){
    this->logic = logic;
    this->board = new Board(BOARD_SIZE, BOARD_SIZE, logic);
    this->screen = screen;
}

void NetGame::run() {
    Client client("127.0.0.1", 8000, logic, board);
    try {
        client.connectToServer();
    } catch (const char *msg) {
        this->screen->showMessage("Failed to connect to server. Reason: ");
        this->screen->showMessage(msg);
        exit(-1);
    }
    //bool isFirstTurn = true;
    this->screen->showBoard(this->board);
     {
        client.readOpponentChoice();
        client.sendChoice();
    }
}

NetGame::~NetGame() {
    delete(this->board);
}