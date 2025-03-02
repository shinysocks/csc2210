#include "TicTacToe.h"

int main() {
    Game* game = new TicTacToe();
    game->play();

    delete game;
    return 0;
}
