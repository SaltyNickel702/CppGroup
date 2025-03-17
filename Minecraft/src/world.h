#include "chunk.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#ifndef WORLD_H
#define WORLD_H

namespace World { //world data
    map<int[2],Chunk> chunks;
    
    int* setBlock (int x, int y, int z, int block); //int[3], make sure to delete array after use. No memory leakage
    int* getBlock (int x, int y, int z);
    
    namespace Camera {
        float pos[3];
        float rot[2]; //pitch, yaw
        float FOV;
    }
    namespace Player {
        float pos[3];
        float rot[2]; //pitch, yaw
        int inventory[10];

        int* getRayTrace (float distance);
    }
}

#endif WORLD_H
