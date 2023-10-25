#include <EngineToolkit/UI/LayoutPrototype.hpp>

namespace EngineToolkit {

namespace UI {

// LayoutPrototype Function Arguments
#define CONTENT LayoutPrototype (*content)(void)
#define MODIFIER Modifier modifier

LayoutPrototype LayoutPrototype::Box(CONTENT, MODIFIER) {
  LayoutPrototype lp = content();

  Element box;
  box.alignment = Alignment::Center;
  box.content = content().element;

  box.position = {};
  box.size = {};

  this->element.push_back(box);

  return *this;
}

LayoutPrototype LayoutPrototype::Column(CONTENT, MODIFIER) {
  LayoutPrototype lp = content();

  return *this;
}

LayoutPrototype LayoutPrototype::Row(CONTENT, MODIFIER) {
  LayoutPrototype lp = content();

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