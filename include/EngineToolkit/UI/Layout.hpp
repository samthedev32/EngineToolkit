#pragma once

#include <EngineToolkit/math/math.hpp>

#include <string>
#include <unordered_map>

namespace EngineToolkit {

namespace UI {

enum class Alignment { Center, Start, End, Top, Bottom };

enum class Type { Box };

struct Element {
    Alignment alignment;
    Type type;
    vec<2> position;
    vec<2> size;
};

// UI Layout
struct Layout {
    // TODO
};

} // namespace UI

} // namespace EngineToolkit