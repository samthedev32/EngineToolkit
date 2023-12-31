#pragma once

#include <EngineToolkit/math/vec.hpp>

#include <string>
#include <unordered_map>
#include <vector>

namespace EngineToolkit::UI {

// Layout Component
struct Component {
  uint32_t typeID;

  // Position and size are proportional to the parent container
  vec<2, float> position, size;
};

// UI Layout
struct Layout {
public:
  // [type - name] table
  std::unordered_map<uint32_t, std::string> table;

  std::vector<Component> components;

  // Save Layout
  bool save(const char *path);

  // Load Layout
  static Layout load(const char *path);
};

}