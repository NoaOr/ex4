/**
 * Noa Or 208385534
 * Amit Hadas 315968263
 */

#include "LocalGame.h"
#include "RegularLogic.h"
#include "HumanPlayer.h"
#include "ConsoleScreen.h"
#include "AIPlayer.h"
#include "NetGame.h"


int main() {
    Screen *screen = new ConsoleScreen();
    int choice = screen->menu();
    Player *player2;
    GameLogic *logic = new RegularLogic();
    Game* game;
    Player *player1= new HumanPlayer(Cell ::X, logic);
    if (choice == 1) {
        player2 = new HumanPlayer(Cell::O, logic);
        game = new LocalGame(logic, player1, player2, screen);
    } else if(choice == 2){
        player2 = new AIPlayer(Cell::O, logic);
        game = new LocalGame(logic, player1, player2, screen);
    } else {
        game = new NetGame(logic, screen, "info.txt");
    }
    game->run();
    delete(logic);
    delete(player1);
  //  delete(player2);
    delete(screen);

}