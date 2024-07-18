#pragma once

#include "../util/util.hpp"

#define FACE_VERTEX_SIZE (4 * 3)
#define FACE_UV_COORDINATES_SIZE (4 * 2)

typedef struct {
    glm::vec2 uv_min, uv_max;
    // TODO: maybe delete to same memory?
    float uv_coordinates[FACE_UV_COORDINATES_SIZE];
} Face;

class BlockMesh {
public:
    void add_face(Direction direction, glm::vec2 uv_min, glm::vec2 uv_max);

    static constexpr float CUBE_VERTICES[] = {
        // NORTH (-z)
        0, 0, 0,
        1, 0, 0,
        0, 1, 0,
        1, 1, 0,

        // SOUTH (+z)
        0, 0, 1,
        1, 0, 1,
        0, 1, 1,
        1, 1, 1,

        // EAST (+x)
        1, 0, 1,
        1, 0, 0,
        1, 1, 1,
        1, 1, 0,

        // WEST (-x)
        0, 0, 1,
        0, 0, 0,
        0, 1, 1,
        0, 1, 0,

        // UP (+y)
        0, 1, 1,
        1, 1, 1,
        0, 1, 0,
        1, 1, 0,

        // DOWN (-y)
        0, 0, 1,
        1, 0, 1,
        0, 0, 0,
        1, 0, 0,
    };
    static constexpr unsigned int CUBE_INDICES[] = {2,  0,  1,  2,  3,  1};

    float uv_coordinates[6 * FACE_UV_COORDINATES_SIZE];
    Face faces[6];
};
