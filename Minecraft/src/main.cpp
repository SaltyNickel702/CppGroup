#define STB_IMAGE_IMPLEMENTATION 
#include "Game.h" //includes all needed includes

int main () {
    thread init(Game::init,800,800);


    init.join();
}