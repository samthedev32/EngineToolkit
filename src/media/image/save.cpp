#include <EngineToolkit/media/image.hpp>

#include <cstdio>
#include <cstring>
#include <string>
#include <zlib.h>

namespace EngineToolkit {

bool Image::savePNG(const char *path) {
  // TODO
  return false;
}

bool Image::saveBMP(const char *path) {
  // TODO
  return false;
}

bool Image::save(const char *path) {
  // Determine File Type
  const char *ext = strrchr(path, '.');

  if (!strcmp(ext, ".png"))
    return savePNG(path);
  else if (!strcmp(ext, ".bmp"))
    return saveBMP(path);
  else
    printf("failed to recognize format\n");

  return false;
}

} // namespace EngineToolkit