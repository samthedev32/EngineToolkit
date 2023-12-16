#pragma once

namespace EngineToolkit::UI {

// TODO: implement some sort of Arrangement System
// it probably won't be based on the compose "Arrangement" object

/**
 * Alignment
 * TODO: description
 */
struct Arrangement {
  /**
   * Vertical Arrangement
   * TODO: description
   */
  enum Vertical {
    CenterVertically,
    Top = 1 << 2,    // bin 0100
    Bottom = 1 << 3, // bin 1000
  } vertical;

  /**
   * Horizontal Alignment
   * TODO: description
   */
  struct Horizontal {
    enum {
      Center,
      Start = 1 << 0, // bin 0001
      End = 1 << 1,   // bin 0010
    } horizontal;
  };

  /**
   * Combined Alignment
   * TODO: description
   */
  enum {
    Center = CenterVertically | Horizontal::Center,
    CenterStart = CenterVertically | Horizontal::Start,
    CenterEnd = CenterVertically | Horizontal::End,

    TopCenter = Top | Horizontal::Center,
    TopStart = Top | Horizontal::Start,
    TopEnd = Top | Horizontal::End,

    BottomCenter = Bottom | Horizontal::Center,
    BottomStart = Bottom | Horizontal::Start,
    BottomEnd = Bottom | Horizontal::End,
  };

  /**
   * Operator to set Alignment to be a Combined Type
   */
  void operator=(typeof(Center) alignment) {
    vertical = CenterVertically;
    if (alignment & Top)
      vertical = Top;
    else if (alignment & Bottom)
      vertical = Bottom;

    horizontal = CenterHorizontally;
    if (alignment & Start)
      horizontal = Start;
    else if (alignment & End)
      horizontal = End;
  }

  // TODO: more constructors

  /**
   * Constructor to create Alignment using a Combined Type
   */
  Alignment(typeof(Center) alignment = Center) {
    *this = alignment;
  }
};

} // namespace EngineToolkit::UI