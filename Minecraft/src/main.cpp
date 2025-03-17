#include "Game.h" //includes all needed includes

int main () {
    thread gameInit(Game::init,600,800);

    gameInit.join();
}