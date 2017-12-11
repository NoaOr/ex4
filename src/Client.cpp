//
// Created by amit on 12/4/17.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <cstring>
#include <unistd.h>
#include "Client.h"
#define MAX_NAME_LEN 300
#define END_SIZE 4
#define NO_MOVE_SIZE 8

Client :: Client(const char *serverIP, int serverPort,
                 GameLogic* gameLogic, Board* board, Screen *screen) :
        serverIP(serverIP), serverPort(serverPort), clientSocket(0), gameLogic(gameLogic),
        player(Cell::Empty, this->gameLogic), board(board), screen(screen){
}
void Client :: connectToServer() {
    // Create a socket point
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        throw "Error opening socket";
    }
    // Convert the ip string to a network address
    struct in_addr address;
    if (!inet_aton(serverIP, &address)) {
        throw "Can't parse IP address";
    }
    // Get a hostent structure for the given host address
    struct hostent *server;
    server = gethostbyaddr((const void *)&address, sizeof
            address, AF_INET);
    if (server == NULL) {
        throw "Host is unreachable";
    }
    // Create a structure for the server address
    struct sockaddr_in serverAddress;
    bzero((char *)&address, sizeof(address));
    serverAddress.sin_family = AF_INET;
    memcpy((char *)&serverAddress.sin_addr.s_addr, (char *)server->h_addr, server->h_length);
    // htons converts values between host and network byte orders
    serverAddress.sin_port = htons(serverPort);
    // Establish a connection with the TCP server
    if (connect(clientSocket, (struct sockaddr
    *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error connecting to server";
    }
    char msgBuff[MAX_NAME_LEN];
    int n = read(clientSocket, &msgBuff, sizeof(msgBuff));
    this->screen->showMessage(msgBuff, n);
    int value;
    n = read(clientSocket, &value, sizeof(value));
    if(n == -1) {
        throw "Error reading value from socket";
    }
    if(value == 1) {
        this->player = HumanPlayer(Cell::X, this->gameLogic);
        this->screen->showMessage("Your value is X.");
    } else {
        this->player = HumanPlayer(Cell::O, this->gameLogic);
        this->screen->showMessage("Your value is O.");
    }
}
bool Client :: sendChoice() {
    if (this->board->isBoardFull()) {
        char endMsg [END_SIZE] = "End";
        int n = write(clientSocket, &endMsg, sizeof(endMsg));
        if (n == -1) {
            throw "Error writing the massage";
        }
        return false;
    }
    if (!player.checkForAnotherMoves(this->board)) {
        char NoMoveMsg [NO_MOVE_SIZE] = "NoMove";
        int n = write(clientSocket, &NoMoveMsg, sizeof(NoMoveMsg));
        if (n == -1) {
            throw "Error writing the massage";
        }
        return true;
    }
    Coordinate choice = this->player.doYourTurn(this->board, this->screen);
        int buffer [2];
        buffer[0] = choice.getRow();
        buffer[1] = choice.getCol();
        Coordinate coor(buffer[0], buffer[1]);
        if (choice.getRow()!= -1 && choice.getCol() != -1) {
            this->board->updateBoard(coor, this->player.getVal());
            this->screen->showPlayersChoice(this->player.getVal(), coor);
            this->screen->showBoard(this->board);
        }

        int n = write(clientSocket, &buffer, sizeof(buffer));
        if (n == -1) {
            throw "Error writing the choice";
        }
    return true;
}
bool Client :: readOpponentChoice() {
    Cell cell(Cell::Empty);
    Cell::Value opponentVal = cell.getOpponentVal(this->player.getVal());
    int buffer[2];
    int n = read(clientSocket, &buffer, sizeof(buffer));
    if(n == -1) {
        throw "Error reading choice from socket";
    }
    Coordinate firstTurnFlag(-1, -1);
    if(isEndMessage(buffer)) {
        return false;
    }
    //No Move -
    if (isNoMoveMsg(buffer)) {
        screen->opponentHasNoMove();
        return true;
    }
    Coordinate coor(buffer[0], buffer[1]);
    if (coor.getRow() > 0 && coor.getCol() > 0) {
        this->board->updateBoard(coor, opponentVal);
        this->screen->showPlayersChoice(opponentVal, coor);
        this->screen->showBoard(this->board);
    }
    //the game can keep going
    return true;
}

bool Client::readMassage() {
    char msg[MAX_NAME_LEN];
    int n = read(clientSocket, &msg, sizeof(msg));
    if (strcmp(msg, "End") == 0) {
        return false;
    }
    if(strcmp(msg, "First turn") != 0) {
        screen->showMessage(msg, n);
    }
    return true;
}

bool Client::isNoMoveMsg(int *buffer) {
    char *str = (char*) buffer;
    if (strcmp(str, "NoMove") == 0) {
        return true;
    }
    return false;
}


bool Client::isEndMessage(int *buffer) {
    char *str = (char*) buffer;
    if (strcmp(str, "End") == 0) {
        return true;
    }
    return false;

}