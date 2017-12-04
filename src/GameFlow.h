/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */
#ifndef EX2_GAMEFLOW_H
#define EX2_GAMEFLOW_H

#include <iostream>
#include "Board.h"
#include "Player.h"
#include "Cell.h"
#include "GameLogic.h"
#include "Screen.h"


class GameFlow {
public:
    /**
     * Constructor.
     * @param logic - the logic of the game.
     * @param player1
     * @param player2
     */
    GameFlow(GameLogic *logic, Player *player1, Player *player2, Screen *screen);
    /**
     * plays one turn - calls the players functions to do there turns.
     */
    void playOneTurn();
    /**
     * checks if the board is full.
     * @return
     */
    bool isBoardFull();
    /**
     * destructor.
     */
    ~GameFlow();
private:
    Board *board;
    GameLogic *logic;
    Player *player1;
    Player *player2;
    Screen *screen;
};


#endif //EX2_GAMEFLOW_H
