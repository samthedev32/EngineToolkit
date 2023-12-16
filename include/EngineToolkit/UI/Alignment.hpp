#pragma once

namespace EngineToolkit::UI {

/**
 * Alignment
 * TODO: description
 */
struct Alignment {
  /**
   * Vertical Alignment
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
  enum Horizontal {
    CenterHorizontally,
    Start = 1 << 0, // bin 0001
    End = 1 << 1,   // bin 0010
  } horizontal;

  /**
   * Combined Alignment
   * TODO: description
   */
  enum {
    Center = CenterVertically | CenterHorizontally,
    CenterStart = CenterVertically | Start,
    CenterEnd = CenterVertically | End,

    TopCenter = Top | CenterHorizontally,
    TopStart = Top | Start,
    TopEnd = Top | End,

    BottomCenter = Bottom | CenterHorizontally,
    BottomStart = Bottom | Start,
    BottomEnd = Bottom | End,
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