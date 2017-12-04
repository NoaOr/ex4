/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */

#include "GameFlow.h"
#include "RegularLogic.h"
#include "HumanPlayer.h"
#include "ConsoleScreen.h"
#include "AIPlayer.h"


int main() {
    Screen *screen = new ConsoleScreen();
    int choice = screen->menu();
    Player *player2;
    GameLogic *logic = new RegularLogic();
    Player *player1= new HumanPlayer(Cell ::X, logic);
    if (choice == 1) {
        player2 = new HumanPlayer(Cell::O, logic);
    } else {
        player2 = new AIPlayer(Cell::O, logic);
    }

    GameFlow game = GameFlow(logic, player1, player2, screen);
    game.playOneTurn();

    delete(logic);
    delete(player1);
    delete(player2);
    delete(screen);

}