#pragma once

#include <EngineToolkit/math/vector/vec2.hpp>

#include <string>
#include <unordered_map>

namespace EngineToolkit {

namespace UI {

enum class Alignment { Center, Start, End, Top, Bottom };

enum class Type { Box };

struct Element {
  Alignment alignment;
  Type type;
  vec2 position;
  vec2 size;
};

// UI Layout
struct Layout {
  // TODO
};

} // namespace UI

} // namespace EngineToolkit