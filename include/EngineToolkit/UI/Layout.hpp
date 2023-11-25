#pragma once

#include <EngineToolkit/math/vec.hpp>

#include <string>
#include <unordered_map>
#include <vector>

namespace EngineToolkit {
namespace UI {

// Performance-Optimized UI Layout
struct Layout {
public:
  std::vector<int> elements;
};

} // namespace UI
} // namespace EngineToolkit