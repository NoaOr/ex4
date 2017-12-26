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
    /**
     * The function shows the options of the player.
     * @param optionsList
     * @param value
     */
    virtual void showOptions(list<Coordinate> optionsList, char value) const;
    /**
     * The function shows the menu and gets a choice from the player.
     * @return - the players choice.
     */
    virtual int menu() const;
    /**
     * The function shows a message on the screen.
     * @param msg
     */
    virtual void showMessage(string msg) const;
    /**
     * The function shows a message on the screen.
     * @param msg
     * @param msgSize
     */
    virtual void showMessage(char msg[], int msgSize) const;
    /**
     * The function tells the player that his opponent has no moves.
     */
    virtual void opponentHasNoMove() const;
    virtual string scanFromUser(int i);
    virtual void showList(list<string> namesList) const;
};


#endif //EX2_CONSOLESCREEN_H
