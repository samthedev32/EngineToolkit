#include "EngineToolkit/UI/Layout.hpp"
#include <EngineToolkit/UI/LayoutPrototype.hpp>
#include <algorithm>
#include <cstdint>
#include <limits>
#include <memory>
#include <stdexcept>
#include <unordered_map>

namespace EngineToolkit {
namespace UI {

Layout Container::build() {
  Layout out;

  // padding will be a modifier for elements, will be same as borderSize
  vec<2, float> padding = {0.08f};

  // Clear temporary and permanent tables
  std::unordered_map<std::string, uint32_t> table;
  out.table.clear();

  for (int i = 0; i < elements.size(); i++) {
    vec<2, float> corner; // top-left corner
    vec<2, float> size;

    switch (alignment) {
    case Alignment::Horizontal:
      size->width = (1.0f - padding->width - elements.size() * padding->width) / elements.size();
      size->height = 1.0f - padding->height * 2;

      corner->x = padding->width + (size->width + padding->width) * i;
      corner->y = padding->height;
      break;

    case Alignment::Vertical:
      size->width = 1.0f - padding->width * 2;
      size->height = (1.0f - padding->height - elements.size() * padding->height) / elements.size();

      corner->x = padding->width;
      corner->y = padding->height + (size->height + padding->height) * i;
      break;

    default:
    case Alignment::None:
      corner = padding;
      size = (vec<2, float>){1.0f} - padding * 2.0f;
      break;
    }

    uint32_t type = 0;
    if (table.count(elements[i].type) == 0) {
      type = table.size();

      // make sure we do not have duplicates
      while (out.table.count(type))
        type++;

      table[elements[i].type] = type;
      out.table[type] = elements[i].type;
    } else
      type = table[elements[i].type];

    Component component;
    component.typeID = type;
    component.position = corner + size / 2.0f;
    component.size = size;
    out.components.push_back(component);
  }

  // TODO Build Containers' Layouts
  // TODO Merge 2 Layouts

  // std::vector<Layout> layouts;
  // for (auto &cont : containers)
  //   layouts.push_back(cont.build());

  return out;
}

LayoutPrototype::LayoutPrototype(ContainerType canvasType) {
  canvas.type = canvasType;

  canvas.elements.clear();
  canvas.containers.clear();

  canvas.position = {};
  canvas.size = {};
}

// Core

LayoutPrototype &LayoutPrototype::Container(LayoutPrototype content, ContainerType type) {
  struct Container container(content.canvas);
  container.type = type;
  canvas.containers.push_back(container);
  return *this;
}

LayoutPrototype &LayoutPrototype::Element(std::string id) {
  struct Element element;
  element.type = id;
  canvas.elements.push_back(element);
  return *this;
}

// Containers

LayoutPrototype &LayoutPrototype::Box(LayoutPrototype content) {
  return Container(content, ContainerType::Box);
}

// Elements

LayoutPrototype &LayoutPrototype::Card() {
  return Element("card");
}

Layout LayoutPrototype::build() {
  return canvas.build();
}

#undef CONTENT
#undef MODIFIER

} // namespace UI

} // namespace EngineToolkit