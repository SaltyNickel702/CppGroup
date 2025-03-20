#include "Game.h" //includes all needed includes

int main () {
    thread gameInit(Game::init,800,800);

    gameInit.join();
}