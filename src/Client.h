//
// Created by amit on 12/4/17.
//

#ifndef EX4_CLIENT_H
#define EX4_CLIENT_H


#include "HumanPlayer.h"
#include "Screen.h"

class Client {
public:
    /**
     * Constructor
     * @param serverIP - the server IP
     * @param serverPort - the port
     * @param gameLogic - the game logic
     * @param board
     * @param screen
     */
    Client(const char *serverIP, int serverPort,
           GameLogic* gameLogic, Board* board, Screen *screen);
    /**
     * The function connects the client to the server.
     */
    void connectToServer();
    /**
     * The function sends the choice of the player to the server.
     * @return bool - true if the game should continue and false otherwise.
     */
    bool sendChoice();
    /**
     * The function receives the choice of the opponent and updates the board.
     * @return bool - true if the game should continue and false otherwise.
     */
    bool readOpponentChoice();
    /**
     * The function reads message from the server.
     * @return bool - true if the game should continue and false otherwise.
     */
    bool readMassage();
    /**
     * The function checks if the received message is a no move message.
     * @param buffer - the message.
     * @return bool - true if the game should continue and false otherwise.
     */
    bool isNoMoveMsg(int *buffer);
    bool isEndMessage(int *buffer);
private:
    const char *serverIP;
    int serverPort;
    int clientSocket;
    HumanPlayer player;
    Board* board;
    GameLogic* gameLogic;
    Screen* screen;
    bool isOtherPlayerHasMove;
};


#endif //EX4_CLIENT_H
