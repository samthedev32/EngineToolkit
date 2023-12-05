#pragma once

#include "Layout.hpp"

#include <variant>

namespace EngineToolkit {
namespace UI {

enum class Alignment { None, Vertical, Horizontal };
enum class Arrangement { Center, CenterVertically, CenterHorizontally };

struct Element {
  vec<2, float> ratio;
  vec<2, float> position, size;

  std::string type;
};

enum class ContainerType { Box = 0, Column, Row, Map };

struct Container {
  ContainerType type;
  Alignment alignment = Alignment::Horizontal;

  std::vector<struct Element> elements;
  std::vector<struct Container> containers;

  vec<2, float> position, size;

  Layout build();
};

// Layout Prototype to build Layouts
class LayoutPrototype {
public:
  LayoutPrototype(ContainerType canvasType = ContainerType::Box);

  // ---- Core

  LayoutPrototype &Container(LayoutPrototype content, ContainerType type);
  LayoutPrototype &Element(std::string id);

  // ---- Containers

  LayoutPrototype &Box(LayoutPrototype content);

  // TODO:
  // 2 core types: Container & Element
  // Must-Haves: Box, Column, Row
  //             Card, etc.            TODO: define!
  // everything builds on the types,
  // the build function defines the container types,
  // and the renderer defines the element types available
  // builder may assign UUIDs to each type of element,
  // then give renderer a map of UUIDs and names

  // LayoutPrototype &Column(LayoutPrototype &content);
  // LayoutPrototype &Row(LayoutPrototype &content);

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
  struct Container canvas;
};

#undef CONTENT
#undef MODIFIER

} // namespace UI
} // namespace EngineToolkit
