#pragma once

#include "Layout.hpp"
#include "Modifier.hpp"

#include <variant>

namespace EngineToolkit {
namespace UI {

enum class Alignment { Center, Start, End, Top, Bottom };
enum class Arrangement { Center, CenterVertically, CenterHorizontally };

struct Elements {
  vec<2, float> position, size;

  std::string type;
};

struct Container;

typedef std::variant<Elements, Container> Element;

struct Container {
  vec<2, float> position, size;
  std::vector<Element> content;
  // TODO
};

// LayoutPrototype Function Arguments
#define CONTENT LayoutPrototype (*content)(void) = NULL
#define MODIFIER Modifier modifier = {}

// Layout Prototype to build Layouts
class LayoutPrototype {
public:
  // ---- Containers

  LayoutPrototype &Box(CONTENT, MODIFIER);

  // LayoutPrototype &Column(CONTENT, MODIFIER);
  // LayoutPrototype &Row(CONTENT, MODIFIER);

  // LayoutPrototype ColumnList(LayoutPrototype (*content)(void));
  // LayoutPrototype RowList(LayoutPrototype (*content)(void));

  // LayoutPrototype Drawer(LayoutPrototype (*content)(void));

  // ---- Basic

  LayoutPrototype &Card();

  // ---- User Input

  // LayoutPrototype &Button();
  // LayoutPrototype &Switch();
  // LayoutPrototype &Joystick();

  // LayoutPrototype &CheckBox();
  // LayoutPrototype &RadioButton();

  // LayoutPrototype &TextField();

  // LayoutPrototype &Slider();
  // LayoutPrototype &Spinner();

  // // ---- Media

  // LayoutPrototype &Image();
  // LayoutPrototype &Icon();
  // LayoutPrototype &Video();

  // LayoutPrototype &Text();

  // // ---- Design & Feedback

  // LayoutPrototype &Divider();
  // LayoutPrototype &Spacer();

  // LayoutPrototype &ProgressBar();
  // LayoutPrototype &ProgressCircle();

  // TODO

  // Build Layout
  Layout build();

private:
  std::vector<Element> elements;
  // TODO
};

#undef CONTENT
#undef MODIFIER

} // namespace UI
} // namespace EngineToolkit
