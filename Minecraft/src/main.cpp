#include "Game.h" //includes all needed includes

void assignBlocks () {
    Block airBlock;
    airBlock.displayName = "Air";
    airBlock.blockType = 0;
    World::blockTypes[0] = airBlock;

    Block grassBlock;
    grassBlock.displayName = "Grass";
    grassBlock.blockType = 1;
    World::blockTypes[1] = grassBlock;

    Block dirtBlock;
    dirtBlock.displayName = "Dirt";
    dirtBlock.blockType = 2;
    World::blockTypes[2] = dirtBlock;

    Block stoneBlock;
    stoneBlock.displayName = "Stone";
    stoneBlock.blockType = 3;
    World::blockTypes[3] = stoneBlock;

    Block woodBlock;
    woodBlock.displayName = "Wood";
    woodBlock.blockType = 4;
    World::blockTypes[4] = woodBlock;

}

int main () {
    

    Game::init(600,600);
}