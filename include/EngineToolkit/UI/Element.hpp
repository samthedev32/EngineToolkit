#pragma once

#include "Layout.hpp"

namespace EngineToolkit {
namespace UI {

enum class Arrangement { None, Vertical, Horizontal };

struct Element {
  vec<2, float> ratio;
  vec<2, float> position, size;

  Arrangement arrangement;
  std::vector<Element> children;

  std::string type;

  Layout build();
};

} // namespace UI
} // namespace EngineToolkit