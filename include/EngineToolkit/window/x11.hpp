#pragma once

#ifndef __linux__
#error OS is not supported
#endif

#include <map>
#include <string>

#include <GL/glx.h>
#include <X11/Xlib.h>

#include <EngineToolkit/math/vec.hpp>

namespace EngineToolkit::internal {

class X11Window {
public:
  vec<2, uint32_t> size;

  X11Window(std::string name, vec<2, uint32_t> size);
  ~X11Window();

  bool update(vec<3, float> color = {});
  void kill(bool sure = true);

  bool key(std::string k);

private:
  // Window Stuff
  Display *display = NULL;
  GLXContext context;

  Window window;

  // Flags
  bool shouldClose = false;
  bool fullscreen = false;

  // Timing
  long past, now;
  float deltaTime;

  // inputs
  std::map<std::string, bool> buttonState;
  bool mouseState[3];
  double cursor_raw[2][2];
};

} // namespace EngineToolkit::internal