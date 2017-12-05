//
// Created by amit on 12/4/17.
//

#include <cstdlib>
#include "NetGame.h"
#define BOARD_SIZE 8
NetGame::NetGame(GameLogic* logic, Screen* screen){
    this->logic = logic;
    this->board = new Board(BOARD_SIZE, BOARD_SIZE, logic);
    this->screen = screen;
}

void NetGame::run() {
    Client client("127.0.0.1", 8000, logic, board, screen);
    try {
        client.connectToServer();
    } catch (const char *msg) {
        this->screen->showMessage("Failed to connect to server. Reason: ");
        this->screen->showMessage(msg);
        exit(-1);
    }

    this->screen->showBoard(this->board);
    for (int i = 0; i < 10; i++) {
        client.readMassage();
        client.readOpponentChoice();
        client.sendChoice();
    }
}

NetGame::~NetGame() {
    delete(this->board);
}