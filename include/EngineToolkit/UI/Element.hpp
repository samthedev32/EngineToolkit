#pragma once

#include "Alignment.hpp"
#include "Layout.hpp"

namespace EngineToolkit::UI {

/**
 * Arrangement of a Container
 *  - None: Elements are put on top of each other
 *  - Vertical (row): Elements are placed vertically to each other
 *  - Horizontal (column): Elements are placed horizontally to each other
 *
 * TODO: space-between (##--##--##), space-around (-##--##--##-), space-evenly (--##--##--##--)
 */
enum class Arrangement { None, Vertical, Horizontal };

/**
 * UI Element
 * TODO
 */
struct Element {
  Alignment alignment;

  // float ratio = 0; // width / height
  float ratio;
  vec<2, float> position;

  // Container Properties
  Arrangement arrangement;
  std::vector<Element> children;

  uint16_t type;
  // uint16_t subType;

  /**
   * Build Element & Children
   */
  Layout build();
};

} // namespace EngineToolkit::UI