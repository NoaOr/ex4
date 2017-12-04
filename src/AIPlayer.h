/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */

#ifndef EX3_AIPLAYER_H
#define EX3_AIPLAYER_H

#include "Player.h"
#include "Screen.h"

class AIPlayer : public Player {
public:
    /**
     * Constructor
     * @param value - the value of the player.
     * @param logic - the game logic.
     */
    AIPlayer(Cell :: Value value, GameLogic* logic);
    /**
     * The function returns a list of options.
     * @param board - The board.
     * @return - list of Coordinates.
     */
    list<Coordinate> getOptionsList(Board *board);
    /**
     * The function checks what is the grade of the opponent's choice.
     * @param board - the board.
     * @param opponentVal - the opponent's value.
     * @return - the grade of the choice.
     */
    int bestOpponentChoice(Board *board, Cell:: Value opponentVal);
    /**
     * The function makes the AIPlayer's move.
     * @param board
     * @param screen
     * @return the AIPlayer's best choice.
     */
    virtual Coordinate doYourTurn(Board *board, Screen *screen);
    /**
     * gets he choice.
     * @param optionsList - list of option cells.
     * @return the chosen coordinate.
     */
    virtual Cell ::Value getVal() const;
    /**
     * checks if the player has more moves.
     * @return boolean
     */
    virtual bool hasMoreMoves();
    /***
     * The function handles the case that AIPlayer's has no moves.
     * @param screen - the screen to show that move passed to another player.
     */
    virtual void movePasses(Screen *screen, char value);
    /**
     * The function shows wht Coordinate the player chose.
     * @param c - the coordinate.
     * @param screen - the screen.
     */
    virtual void showChoice(Coordinate c, Screen *screen) const;


private:
    Cell::Value value;
    GameLogic *logic;
    bool hasMove;

};


#endif //EX3_AIPLAYER_H
