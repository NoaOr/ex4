/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */
#ifndef EX2_CONSOLESCREEN_H
#define EX2_CONSOLESCREEN_H


#include "Board.h"
#include "Screen.h"
#include "Player.h"

class ConsoleScreen : public Screen {
public:
    /**
     * the function shows the screen.
     * @param board - the board.
     */
    virtual void showBoard(Board *board);
    /**
     * the function counts the number of X's and O's and
     * @param board
     */
    virtual void gameOverScreen(Board *board);
    /**
     * The function prints the player's choice.
     * @param val - the player's value.
     * @param c - the coordinate that the player chose.
     */
    virtual void showPlayersChoice(Cell::Value val, Coordinate c);

    /**
     * The function prints that the move passes to the other player.
     * @param val - the player's value.
     */
    virtual void showMovePasses(Cell::Value val) const;
    /**
     * The function shows that the chosen move is unvalid.
     */
    virtual void showUnValidMove() const;

    virtual void showOptions(list<Coordinate> optionsList, char value) const;
    virtual int menu() const;

};


#endif //EX2_CONSOLESCREEN_H
