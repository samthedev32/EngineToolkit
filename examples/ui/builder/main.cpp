#include <EngineToolkit/UI/Layout.hpp>
#include <EngineToolkit/UI/LayoutPrototype.hpp>
#include <EngineToolkit/UI/ui.hpp>

#include <ctime>

#include "window.hpp"

using namespace EngineToolkit;

// WARNING:
// This example is only to show how UI building works,
// and not how to make a functional renderer.
// While the windowing/rendering code is functional,
// it is highly NOT RECOMMENDED to use in apps

int main() {
  UI::LayoutPrototype prototype(UI::Arrangement::Vertical);

  prototype.Box([&] {
    UI::LayoutPrototype p(UI::Arrangement::Horizontal);

    p.Element("card", 1);
    p.Element("card", 1);
    p.Box([&] {
      UI::LayoutPrototype p(UI::Arrangement::Vertical);

      p.Element("card", 1);
      p.Element("card", 1);

      return p;
    }());

    return p;
  }());

  prototype.Element("card", 1);
  prototype.Element("card", 2);
  prototype.Element("card", 2);

  UI::Layout layout = prototype.build();
  // layout.save("test.layout");

  // UI::Layout layout = UI::Layout::load("test.layout");

  Window window("UI Builder");

  int seed = time(0);

  // Set Draw Mode
  window.setMode(LINE);

  // Main Loop
  while (window.update()) {
    srand(seed);

    const vec<2, float> center = {0.0f, 0.0f};
    vec<2, float> size = {1.0f, (float)window.size->width / window.size->height};

    // Draw Canvas
    window.setColor({1});
    window.quad(center, size);

    // Draw UI Bounding Rects
    for (auto c : layout.components) {

      float x = (center->x - size->x / 2.0f) + c.position->x * size->x;
      float y = (center->y + size->y / 2.0f) - c.position->y * size->y;
      // NOTE: y is different from x since gpus start from the left-bottom corner
      // and UI in general from the top-left
      float w = c.size->width * size->width;
      float h = c.size->height * size->height;

      // Generate Color for each UI element
      // since we set the same seed every frame,
      // the color will stay the same (per component)
      window.setColor({(rand() % 100) / 100.0f, (rand() % 100) / 100.0f, (rand() % 100) / 100.0f});

      // Draw Element
      window.quad({x, y}, {w, h});
    }
  }

  return 0;
}