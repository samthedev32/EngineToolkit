#include <EngineToolkit/UI/Element.hpp>

namespace EngineToolkit {
namespace UI {

Layout Element::build() {
  Layout out;

  // NOTE: will be a per-element modifier
  vec<2, float> padding = {0.02f};

  // Clear temporary and permanent tables
  std::unordered_map<std::string, uint32_t> table;
  out.table.clear();

  for (int i = 0; i < children.size(); i++) {
    vec<2, float> corner; // top-left corner
    vec<2, float> size;

    switch (arrangement) {
    case Arrangement::Horizontal:
      size->width = (1.0f - padding->width - children.size() * padding->width) / children.size();
      size->height = 1.0f - padding->height * 2;

      corner->x = padding->width + (size->width + padding->width) * i;
      corner->y = padding->height;
      break;

    case Arrangement::Vertical:
      size->width = 1.0f - padding->width * 2;
      size->height = (1.0f - padding->height - children.size() * padding->height) / children.size();

      corner->x = padding->width;
      corner->y = padding->height + (size->height + padding->height) * i;
      break;

    default:
    case Arrangement::None:
      corner = padding;
      size = vec<2, float>{1.0f} - padding * 2.0f;
      break;
    }

    uint32_t type = 0;
    if (table.count(children[i].type) == 0) {
      type = table.size();

      // make sure we do not have duplicates
      while (out.table.count(type))
        type++;

      table[children[i].type] = type;
      out.table[type] = children[i].type;
    } else
      type = table[children[i].type];

    // TODO Build Children Here
    Component component;
    component.typeID = type;
    component.position = corner + size / 2.0f;
    component.size = size;
    out.components.push_back(component);

    Layout l = children[i].build();
    for (auto ll : l.components) {
      printf("%f %f\n", ll.position->x, ll.position->y);
      ll.position = corner + ll.position * size;
      ll.size *= size;
      out.components.push_back(ll);
    }

    out.table.merge(l.table);
  }

  return out;
}

} // namespace UI
} // namespace EngineToolkit