#include "EngineToolkit/UI/Layout.hpp"
#include "EngineToolkit/UI/LayoutPrototype.hpp"
#include <EngineToolkit/UI/ui.hpp>

using namespace EngineToolkit;

void asd(UI::LayoutPrototype lp);

int main() {
  UI::LayoutPrototype prototype;

  prototype.Box([] {
    UI::LayoutPrototype prototype;
    prototype.Card();
    return prototype;
  });

  // prototype.Box(NULL, UI::Modifier().size(1));

  // prototype.Column([] {
  //   UI::LayoutPrototype l;
  //   l.Button();
  //   return l;
  // });

  // UI::Layout layout = prototype.build();

  // TODO

  return 0;
}