/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */

#ifndef EX2_SCREEN_H
#define EX2_SCREEN_H


#include <vector>
#include "Board.h"
#include "Player.h"

class Screen {
public:
    /**
     * the function shows the screen.
     * @param board - the board.
     */
    virtual void showBoard(Board *board) = 0;
/**
 * prints the winner value.
 * @param board - the board.
 */
    virtual void gameOverScreen(Board *board) = 0;
    /**
     * The function shows what was the player's choice.
     * @param val - the player's value.
     * @param c - the player's choice.
     */
    virtual void showPlayersChoice(Cell::Value val, Coordinate c) = 0;
    /**
     * The function shows that the move passes to the other player.
     * @param val - The player's value.
     */
    virtual void showMovePasses(Cell::Value val) const = 0;
    /**
     * The function handles the case that the player chose un valid coordinate.
     */
    virtual void showUnValidMove() const = 0;

    virtual void showOptions(list<Coordinate> optionsList, char value) const = 0;
    /**
     * The function shows the menu and gets choice from the player.
     * @return player choice
     */
    virtual int menu() const = 0;
    virtual void showMessage(string msg) const = 0;
    virtual void showMessage(char msg[], int msgSize) const = 0;
    virtual void opponentHasNoMove() const = 0;
    virtual string scanFromUser(int i) = 0;
    virtual void showList(list<string> namesList) const = 0;
};


#endif //EX2_SCREEN_H
