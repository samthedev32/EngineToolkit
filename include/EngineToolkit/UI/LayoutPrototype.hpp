#pragma once

#include "Layout.hpp"

namespace EngineToolkit {

namespace UI {

struct Modifier {
  // TODO
};

// Layout Builder
class LayoutPrototype {
public:
  // ---- Containers

  LayoutPrototype Card(LayoutPrototype content);

  LayoutPrototype Column(LayoutPrototype content);
  LayoutPrototype Row(LayoutPrototype content);

  LayoutPrototype ColumnList(LayoutPrototype content);
  LayoutPrototype RowList(LayoutPrototype content);

  LayoutPrototype Drawer(LayoutPrototype content);

  // ---- User Input

  LayoutPrototype Button();
  LayoutPrototype Switch();
  LayoutPrototype Joystick();

  LayoutPrototype CheckBox();
  LayoutPrototype RadioButton();

  LayoutPrototype TextField();

  LayoutPrototype Slider();
  LayoutPrototype Spinner();

  // ---- Media

  LayoutPrototype Image();
  LayoutPrototype Icon();
  LayoutPrototype Video();

  LayoutPrototype Text();

  // ---- Design & Feedback

  LayoutPrototype Box();

  LayoutPrototype Divider();
  LayoutPrototype Padding();

  LayoutPrototype ProgressBar();
  LayoutPrototype ProgressCircle();

  // TODO

  // Build Layout
  Layout build();

private:
  // std::vector<Element> element;
  // TODO
};

} // namespace UI

} // namespace EngineToolkit
