#pragma once

#include "Element.hpp"

namespace EngineToolkit {
namespace UI {

// Layout Prototype to build Layouts
class LayoutPrototype {
public:
  LayoutPrototype(Arrangement arrangement = Arrangement::Vertical);

  // ---- Core

  LayoutPrototype &Container(LayoutPrototype content, Arrangement arrangement);
  LayoutPrototype &Element(std::string id, float ratio);

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
  void rebuild();
  Layout build();

private:
  struct Element canvas;
};

#undef CONTENT
#undef MODIFIER

} // namespace UI
} // namespace EngineToolkit
