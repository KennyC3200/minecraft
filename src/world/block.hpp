#pragma once

#include "../gfx/sprite_atlas.hpp"
#include "block_mesh.hpp"

typedef uint64_t BlockData;
// - 28 bits metadata/extra
// - 4 bits sunlight intensity
// - 4 bits R light
// - 4 bits G light
// - 4 bits B light
// - 4 bits light intensity
// - 16 bits block id

#define BLOCK_DATA_ID_GET(data) (data & 0xffff)
#define BLOCK_DATA_ID_SET(data, id) (data = (data & 0xffffffffffff0000) + (uint64_t) id)
#define BLOCK_DATA_LIGHT_GET(data) ((data >> 16) & 0xf)
#define BLOCK_DATA_LIGHT_SET(data, intensity) (data = (data & 0xfffffffffff0ffff) + (uint64_t) (intensity << 16))
#define BLOCK_DATA_RGB_GET(data) ((data >> 20) & 0xfff)
#define BLOCK_DATA_RGB_SET(data, rgb) (data = (data & 0xffffffff000fffff) + (uint64_t) (rgb << 20))
#define BLOCK_DATA_R_GET(data) ((data >> 20) & 0xf)
#define BLOCK_DATA_R_SET(data, r) (data = (data & 0xffffffffff0fffff) + (uint64_t) (r << 20))
#define BLOCK_DATA_G_GET(data) ((data >> 24) & 0xf)
#define BLOCK_DATA_G_SET(data, g) (data = (data & 0xfffffffff0ffffff) + (uint64_t) (g << 24))
#define BLOCK_DATA_B_GET(data) ((data >> 28) & 0xf)
#define BLOCK_DATA_B_SET(data, g) (data = (data & 0xffffffff0fffffff) + (uint64_t) (b << 28))

enum BlockID {
    BLOCK_NONE = -1,
    BLOCK_AIR = 0,
    BLOCK_GRASS,
    BLOCK_DIRT,
    BLOCK_STONE,
    BLOCK_SAND,
    BLOCK_LOG,
    BLOCK_PLANK,
    BLOCK_LAST,
};

class Block {
public:
    Block();
    ~Block();
    Block(BlockID id, BlockMesh mesh);

    static SpriteAtlas atlas;
    static Block blocks[BLOCK_LAST];

    BlockID id;
    BlockMesh mesh;
private:
    friend class World;

    static void init();
};
