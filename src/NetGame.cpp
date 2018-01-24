//
// Created by amit on 12/4/17.
//

#include <cstdlib>
#include "NetGame.h"
#include "FileReader.h"

#define BOARD_SIZE 8
NetGame::NetGame(GameLogic* logic, Screen* screen, char *fileName){
    this->logic = logic;
    this->board = new Board(BOARD_SIZE, BOARD_SIZE, logic);
    this->screen = screen;
    this->fileName = fileName;
}

void NetGame::run() {
    int isGameContinue;
    FileReader fileReader (this->fileName);
    char *IP = fileReader.getIP();
    int port = fileReader.getPort();
    Client client(IP, port, logic, board, screen);
    try {
        isGameContinue = client.connectToServer();
        if (isGameContinue == false) {
            return;
        }
    } catch (const char *msg) {
        this->screen->showMessage("Failed to connect to server. Reason: ");
        this->screen->showMessage(msg);
        exit(-1);
    }
    this->screen->showBoard(this->board);
    while (true) {
        isGameContinue = client.readMassage();
        if (isGameContinue == false) {
            break;
        }
        isGameContinue = client.readOpponentChoice();
        if (isGameContinue == false) {
            break;
        }
        isGameContinue = client.sendChoice();
        if (isGameContinue == false) {
            break;
        }
    }
    this->screen->gameOverScreen(this->board);
}

NetGame::~NetGame() {
    delete(this->board);
}
