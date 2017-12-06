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
    char msgBuff[300];
    int n = read(clientSocket, &msgBuff, sizeof(msgBuff));
    this->screen->showMessage(msgBuff, n);
    int value;
    n = read(clientSocket, &value, sizeof(value));
    if(n == -1) {
        throw "Error reading value from socket";
    }
    if(value == 1) {
        this->player = HumanPlayer(Cell::X, this->gameLogic);
    } else {
        this->player = HumanPlayer(Cell::O, this->gameLogic);
    }
}
int Client :: sendChoice() {
    Coordinate choice = this->player.doYourTurn(this->board, this->screen);
    Coordinate coor(-1, -1);
    if(&choice != &coor) {
        int buffer [2];
        buffer[0] = choice.getRow();
        buffer[1] = choice.getCol();
        Coordinate coor(buffer[0], buffer[1]);
        this->board->updateBoard(coor, this->player.getVal());
        this->screen->showPlayersChoice(this->player.getVal(), coor);
        this->screen->showBoard(this->board);
        int n = write(clientSocket, &buffer, sizeof(buffer));
        if (n == -1) {
            throw "Error writing the choice";
        }
    }
}
int Client :: readOpponentChoice() {
    Cell cell(Cell::Empty);
    Cell::Value opponentVal = cell.getOpponentVal(this->player.getVal());
    int buffer[2];
    int n = read(clientSocket, &buffer, sizeof(buffer));
    // this->screen->showMessage((char *)buffer);
    if(n == -1) {
        throw "Error reading choice from socket";
    }
    Coordinate firstTurnFlag(-1, -1);
    Coordinate coor(buffer[0], buffer[1]);
    if (coor.getRow() != -1 || coor.getCol() != -1) {
        this->board->updateBoard(coor, opponentVal);
        this->screen->showPlayersChoice(opponentVal, coor);
        this->screen->showBoard(this->board);
    }
}

void Client::readMassage() {
    char msg[300];
    int n = read(clientSocket, &msg, sizeof(msg));
    if(strcmp(msg, "First turn") != 0) {
        screen->showMessage(msg, n);
    }
}