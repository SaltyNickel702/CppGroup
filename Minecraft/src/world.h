#include "chunk.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#ifndef WORLD_H
#define WORLD_H

namespace World { //world data
    map<int[2],Chunk> chunks;
    map<int,Block> blockTypes;
    
    int* setBlock (int x, int y, int z, int block); //int[3], make sure to delete array after use. No memory leakage
    int* getBlock (int x, int y, int z);
    
    namespace Camera {
        extern float pos[3];
        extern float rot[2]; //pitch, yaw
        extern float FOV;
    }
    namespace Player {
        extern float pos[3];
        extern float rot[2]; //pitch, yaw
        extern int inventory[10];

        int* getRayTrace (float distance);
    }
}

#endif
