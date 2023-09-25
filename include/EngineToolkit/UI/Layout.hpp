#pragma once

#include <EngineToolkit/core/vector.hpp>

#include <string>
#include <unordered_map>

namespace EngineToolkit {

namespace UI {

enum class Alignment { Center, Start, End, Top, Bottom };

struct Element {
  Alignment alignment;
  vec<2> position;
  vec<2> size;
};

// UI Layout
struct Layout {
  // TODO
};

} // namespace UI

} // namespace EngineToolkit