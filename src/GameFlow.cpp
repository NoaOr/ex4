/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */
#include "GameFlow.h"
#define BOARD_SIZE 8

GameFlow ::GameFlow(GameLogic *logic, Player *player1, Player *player2, Screen *screen) {
    this->board = new Board(BOARD_SIZE, BOARD_SIZE, logic);
    this->logic = logic;
    this->player1 = player1;
    this->player2 = player2;
    this->screen = screen;
}

void GameFlow ::playOneTurn() {
    this->screen->showBoard(this->board);

    while (player1->hasMoreMoves() || player2->hasMoreMoves()) {
        if (this->isBoardFull()) {
            break;
        }
        Coordinate coor = player1->doYourTurn(this->board, this->screen);
        if (player1->hasMoreMoves()) {
            this->board->updateBoard(coor, player1->getVal());
            player1 -> showChoice(coor, screen);
            this->screen->showBoard(this->board);
        }
        if (this->isBoardFull()) {
            break;
        }
        coor = player2->doYourTurn(this->board, this->screen);
        if (player2->hasMoreMoves()) {
            this->board->updateBoard(coor, player2->getVal());
            player2 -> showChoice(coor, screen);
            this->screen->showBoard(this->board);
        }
    }
    this->screen->gameOverScreen(board);

}
bool GameFlow ::isBoardFull() {
    bool isFull = true;
    for (int i = 0; i < this->board->getRowSize(); i++) {
        for (int j = 0; j < this->board->getColSize(); j++) {
            if (this->board->getCellAt(Coordinate(i,j))->getValue() == Cell ::Empty) {
                isFull = false;
            }
        }
    }
    return isFull;
}



GameFlow ::~GameFlow() {
    delete(board);

}