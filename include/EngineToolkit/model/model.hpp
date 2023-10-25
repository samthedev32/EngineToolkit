#pragma once

#include "material.hpp"

#include <EngineToolkit/math/math.hpp>

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace EngineToolkit {

struct Vertex {
    vec<3> position;
    vec<2> texCoord;
    vec<3> normal;
};

struct Model {
    std::vector<Vertex> vertices;
    std::vector<uint16_t> indices;

    // Wavefront OBJ
    struct OBJ {
        std::unordered_map<std::string, Model> model;
        Material::MTL material;

        // TODO: material maps

        static OBJ load(const char *path);
    };
};

} // namespace EngineToolkit