#include <EngineToolkit/UI/Element.hpp>

namespace EngineToolkit::UI {

Layout Element::build() {
  Layout out;

  std::vector<Layout> ch;
  std::vector<float> ratios;
  vec<2, float> sum;

  // // Build Children
  // for (int i = 0; i < children.size(); i++) {
  //   Layout l = children[i].build();
  //   for (int j = 0; j < l.components.size(); j++) {
  //     // l.components[j].size
  //   }

  //   ch.push_back(l);
  //   for (auto ll : l.components) {
  //     ll.position = corner + ll.position * size;
  //     ll.size *= size;
  //     out.components.push_back(ll);
  //   }
  // }

  // // out.table.merge(l.table);

  // vec<2, float> corner; // top-left corner
  // vec<2, float> size;

  // switch (arrangement) {
  // case Arrangement::Horizontal:
  //   size->width = (1.0f - padding->width - children.size() * padding->width) / children.size();
  //   // size->height = 1.0f - padding->height * 2;
  //   size->height = size->width / children[i].ratio;

  //   corner->x = padding->width + (size->width + padding->width) * i;
  //   corner->y = padding->height;
  //   break;

  // case Arrangement::Vertical:
  //   size->height = (1.0f - padding->height - children.size() * padding->height) /
  //   children.size();
  //   // size->width = 1.0f - padding->width * 2;
  //   size->width = size->height * children[i].ratio;

  //   corner->x = padding->width;
  //   corner->y = padding->height + (size->height + padding->height) * i;
  //   break;

  // default:
  // case Arrangement::None:
  //   corner = padding;
  //   size = (vec<2, float>{1.0f} - padding * 2.0f) * children[i].ratio;
  //   break;
  // }

  // // uint32_t type = 0;
  // // if (table.count(children[i].type) == 0) {
  // //   type = table.size();

  // //   // make sure we do not have duplicates
  // //   while (out.table.count(type))
  // //     type++;

  // //   table[children[i].type] = type;
  // //   out.table[type] = children[i].type;
  // // } else
  // //   type = table[children[i].type];

  // Component component;
  // component.typeID = children[i].type;
  // component.position = corner + size / 2.0f;
  // component.size = size;
  // out.components.push_back(component);

  // Build Self
  // TODO: add to `out` Layout

  return out;
}

} // namespace EngineToolkit::UI