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
#define MAX_NAME_LEN 300

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
        char fileName[MAX_NAME_LEN] = "definitions.txt";
        game = new NetGame(logic, screen, fileName);
    }
    game->run();
    delete(logic);
    delete(player1);
    if (choice == 1 || choice == 2) {
        delete(player2);
    }
    delete(screen);
    delete(game);


}