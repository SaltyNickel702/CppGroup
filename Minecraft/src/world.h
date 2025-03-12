#include "chunk.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

#ifndef WORLD_H
#define WORLD_H

namespace World { //world data
    map<int[2],Chunk> chunks;
    
    void setBlock (int x, int y, int z, int block);
    void getBlock (int x, int y, int z);
    
    float Camera[5]; //xyz + pitch + yaw
}

#endif WORLD_H