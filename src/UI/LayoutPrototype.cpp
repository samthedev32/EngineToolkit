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
  canvas.ratio = {};                  // TODO maybe definable
  canvas.position = canvas.size = {}; // undefined
  canvas.arrangement = arrangement;
  canvas.children.clear();
  canvas.type = "canvas";
}

// Core

LayoutPrototype &LayoutPrototype::Container(LayoutPrototype content, Arrangement arrangement) {
  struct Element element(content.canvas);
  element.type = "container";
  canvas.children.push_back(element);
  return *this;
}

LayoutPrototype &LayoutPrototype::Element(std::string id) {
  struct Element element;
  element.type = id;
  canvas.children.push_back(element);
  return *this;
}

// Containers

LayoutPrototype &LayoutPrototype::Box(LayoutPrototype content) {
  return Container(content, Arrangement::None);
}

// Elements

LayoutPrototype &LayoutPrototype::Card() {
  return Element("card");
}

Layout LayoutPrototype::build() {
  return canvas.build();
}

#undef CONTENT
#undef MODIFIER

} // namespace UI

} // namespace EngineToolkit