#pragma once

#include "chunk_mesh.hpp"
#include "block.hpp"
#include "../player/player.hpp"

class Chunk {
public:
    Chunk(glm::vec<3, int> position);
    ~Chunk();

    static void init(Player *player);
    void render();

    glm::vec<3, int> position;
private:
    static Player *player;

    // chunk data stored in a 3d array
    // each u64 has the following bit fields:
    // - 28 bits metadata/extra
    // - 4 bits sunlight intensity
    // - 4 bits R light
    // - 4 bits G light
    // - 4 bits B light
    // - 4 bits light intensity
    // - 16 bits block id
    uint64_t *data;

    ChunkMesh *mesh;
};
