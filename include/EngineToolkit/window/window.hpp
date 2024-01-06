#pragma once

#ifdef __linux__ // Linux

#ifdef WINDOW_USE_XORG // force Xorg
#warning why would you do that?
#include "xorg.hpp"
#else
#include "wayland.hpp"
#endif

#elif !defined(_WIN32)
// TODO: windows flags...
#include "win32.hpp"
#else // Unknown OS
#error OS Not Supported
// TODO: Android & Emscripten support
#endif

namespace EngineToolkit {

class Window {
public:
  Window();
  ~Window();

private:
};

} // namespace EngineToolkit