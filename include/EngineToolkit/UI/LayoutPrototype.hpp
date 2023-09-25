#pragma once

#include "Layout.hpp"

namespace EngineToolkit {

namespace UI {

// Layout Builder
class LayoutPrototype {
public:
  // Build Layout
  Layout build();

  // Clear Layout
  void clear();

  void box();

  void Button();
  void Switch();
  void Joystick();

  void CheckBox();
  void RadioButton();

  void TextField();

  void Image();
  void Icon();
  void Video();

  void Text();

  void slider();
  void spinner();
  void list();
  void card();

  void Divider();
  void Padding();

  void progressbar();
  void progresscircle();

  void radio();     // search & see list: UI Elements
  void accordion(); // search & see list: UI Element List

  // TODO

private:
  // TODO
};

} // namespace UI

} // namespace EngineToolkit
