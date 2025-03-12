class Chunk {
    int blocks[16][16][64]; //xyz

    const int getChunkMesh (); //replace int with data type
    static int joinChunks (int x, int y, Chunk chunks[]);
};