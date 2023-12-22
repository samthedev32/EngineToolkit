#include <EngineToolkit/UI/LayoutPrototype.hpp>

#include <algorithm>
#include <cstdint>
#include <limits>
#include <memory>
#include <stdexcept>
#include <unordered_map>

namespace EngineToolkit {
namespace UI {

LayoutPrototype::LayoutPrototype(Arrangement arrangement) {
  // Set Up Canvas
  canvas.arrangement = arrangement;
  canvas.ratio = 0;
  canvas.children.clear();
  canvas.type = 0;
}

// Core

LayoutPrototype &LayoutPrototype::Container(LayoutPrototype content, Arrangement arrangement) {
  struct Element element(content.canvas);
  element.type = 0;

  // Calculate ratio
  // TODO check
  vec<2> ratio;
  for (auto &c : element.children) {
    float w = 1.0f / c.ratio;
    switch (arrangement) {
    default:
    case Arrangement::None:
      ratio->x = std::max(ratio->x, w);
      ratio->y = std::max(ratio->y, 1.0f);
      break;

    case Arrangement::Vertical:
      ratio->x = std::max(ratio->x, w);
      ratio->y += 1.0f;
      break;

    case Arrangement::Horizontal:
      ratio->x += w;
      ratio->y = std::max(ratio->y, 1.0f);
      break;
    }
  }
  element.ratio = ratio->width / ratio->height;

  canvas.children.push_back(element);
  return *this;
}

LayoutPrototype &LayoutPrototype::Element(std::string id, float ratio) {
  struct Element element;
  element.type = 1;
  element.ratio = ratio;
  canvas.children.push_back(element);
  return *this;
}

// Containers

LayoutPrototype &LayoutPrototype::Box(LayoutPrototype content) {
  return Container(content, Arrangement::None);
}

// Elements

LayoutPrototype &LayoutPrototype::Card() {
  return Element("card", 1);
}

Layout LayoutPrototype::build() {
  return canvas.build();
}

#undef CONTENT
#undef MODIFIER

} // namespace UI

} // namespace EngineToolkit