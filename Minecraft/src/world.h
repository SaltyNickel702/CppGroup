#include "chunk.h"
#include <iostream>
#include <vector>
#include <map>
#include "Block.h"

using namespace std;

#ifndef WORLD_H
#define WORLD_H

namespace World { //world data
    extern map<int, map<int,Chunk>> chunks;
    const vector<float*> getChunkMesh (int cx, int cy); //two float arrays, one for vertices, one for indices
    static vector<float*> joinChunkMeshes (int x, int y, Chunk chunks[]);

    extern map<int,Block> blockTypes;
    
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
