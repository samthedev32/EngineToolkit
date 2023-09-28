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

  // ---- User Input

  void Button();
  void Switch();
  void Joystick();

  void CheckBox();
  void RadioButton();

  void TextField();

  void Slider();
  void Spinner();

  // ---- Media

  void Image();
  void Icon();
  void Video();

  void Text();

  // ---- Design & Feedback

  void Box();

  void Divider();
  void Padding();

  void ProgressBar();
  void ProgressCircle();

  // ---- Container

  void Card();
  void Column();
  void Row();
  void ColumnList();
  void RowList();
  void Drawer();

  // ---- MISC

  void radio();     // search & see list: UI Elements
  void accordion(); // search & see list: UI Element List

  // TODO

private:
  // TODO
};

} // namespace UI

} // namespace EngineToolkit
