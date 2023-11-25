#pragma once

#include <EngineToolkit/math/vec.hpp>

namespace EngineToolkit {
namespace UI {

enum {
  ETK_CALLBACK_ONCLICK = 0,
  // TODO: more callbacks
};

// Modifier Callback Function Arguments
#define CALLBACK bool (*func)(uint32_t)

struct Modifier {
  // ---- Data

  struct {
    // Transform
    vec<2> space = {1.0f, 1.0f};
    vec<2> size = {1.0f, 1.0f};
    float rotation = 0.0f;

    // Callbacks <flags, function*>
    std::vector<std::pair<uint32_t, bool (*)(uint32_t)>> callback = {};
  } data;

  // ---- Size

  Modifier width(float value);
  Modifier height(float value);

  Modifier size(float all);
  Modifier size(float width, float height);
  Modifier size(vec<2> values);

  Modifier fillMaxWidth(float value = 1.0f);
  Modifier fillMaxHeight(float value = 1.0f);
  Modifier fillMaxSize(float value = 1.0f);

  Modifier aspectRatio(float ratio, bool matchHeightConstrainsFirst = false);

  Modifier matchParentSize();

  // ---- Transform

  Modifier rotate(float degrees);

  Modifier scale(float x, float y);
  Modifier scale(float all);
  Modifier scale(vec<2> all);

  Modifier offset(float x, float y);
  Modifier offset(float all);
  Modifier offset(vec<2> values);

  // ---- Other

  Modifier padding(float start, float end, float top, float bottom);
  Modifier padding(float horizontal, float vertical);
  Modifier padding(float all);
  Modifier padding(vec<4> values);

  // ---- Callbacks

  Modifier callback(uint32_t flags, CALLBACK);
  Modifier onHover(CALLBACK);
  Modifier onClick(CALLBACK);

  // TODO

  // TODO: interactive stuff
};

#undef CALLBACK

} // namespace UI
} // namespace EngineToolkit