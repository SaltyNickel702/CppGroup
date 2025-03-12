#ifndef CHUNK_H
#define CHUNK_H

class Chunk {
    static int chunkCoordToWorld (int cx, int cy, float x, float y, float z); //chunk x and y, and relative xyz of coord

    int blocks[16][16][64]; //xyz

    const int getChunkMesh (); //replace int with data type
    static int joinChunkMeshes (int x, int y, Chunk chunks[]);
    static Chunk genChunk(int cx, int cy);

    void setBlock(float x, float y, float z, int blockType);
    int getBlock(float x, float y, float z);
};


#endif CHUNK_H