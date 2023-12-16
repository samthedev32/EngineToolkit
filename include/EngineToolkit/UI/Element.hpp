#pragma once

#include "Alignment.hpp"
#include "Layout.hpp"

namespace EngineToolkit::UI {

/**
 * Arrangement of a Container
 *  - None: Elements are put on top of each other
 *  - Vertical: Elements are placed vertically to each other (row)
 *  - Horizontal: Elements are placed horizontally to each other (column)
 *
 * TODO: actually usable Arrangement in "Arrangement.hpp"
 */
enum class Arrangement { None, Vertical, Horizontal };

/**
 * UI Element
 * TODO
 */
struct Element {
  Alignment alignment;

  float scale = 1.0f; // scale of the element compared to the maximum size

  bool flipRatio = false; // Scale element by width or by height
  float ratio;            // if flipRatio is... false: ratio=width/height | true: ratio=height/width

  vec<2, float> position;

  // Container Properties
  struct {
    Arrangement arrangement;
    std::vector<Element> children;
  };

  std::string type;
  // uint16_t type;
  // uint16_t subType;

  Layout build();
};

} // namespace EngineToolkit::UI