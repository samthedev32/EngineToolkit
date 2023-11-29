#include <EngineToolkit/UI/LayoutPrototype.hpp>

namespace EngineToolkit {

namespace UI {

// LayoutPrototype Function Arguments
#define CONTENT LayoutPrototype (*content)(void)
#define MODIFIER Modifier modifier

LayoutPrototype &LayoutPrototype::Box(CONTENT, MODIFIER) {
  Container box;

  box.position = {};
  box.size = {};

  box.content = content().elements;

  elements.push_back(box);

  return *this;
}

Layout LayoutPrototype::build() {
  Layout out;

  return out;
}

#undef CONTENT
#undef MODIFIER

} // namespace UI

} // namespace EngineToolkit