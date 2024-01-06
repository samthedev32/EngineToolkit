#include <EngineToolkit/window/x11.hpp>

using namespace EngineToolkit::internal;

// Note: window/x11 is not meant to be used directly

int main() {
  X11Window window("X11 Window", {720, 480});

  while (window.update()) {
    // TODO
  }

  return 0;
}