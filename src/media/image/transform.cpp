#include <EngineToolkit/media/image.hpp>

#include <algorithm>

namespace EngineToolkit {

void Image::flip(typeof(Image::Vertically) orientation) {
  switch (orientation) {
  default:
  case Image::Vertically:
    for (uint32_t x = 0; x < size->width; x++)
      for (uint32_t y = 0; y < size->height / 2; y++)
        for (uint8_t ch = 0; ch < channels; ch++)
          std::swap((*this)(x, y)[ch], (*this)(x, size->height - y - 1)[ch]);
    break;

  case Image::Horizontally:
    for (uint32_t x = 0; x < size->width / 2; x++)
      for (uint32_t y = 0; y < size->height; y++)
        for (uint8_t ch = 0; ch < channels; ch++)
          std::swap((*this)(x, y)[ch], (*this)(size->width - x - 1, y)[ch]);
    break;
  }
}

void Image::rotate(typeof(Image::Clockvise) direction) {
  switch (direction) {
  default:
  case Image::Clockvise:
    for (uint32_t x = 0; x < size->width / 2; x++) {
      for (uint32_t y = 0; y < size->height / 2; y++) {
        // (*this)(x, y)[ch]
        // (*this)(size->width - y - 1, x)[ch]
        // (*this)(size->width - x - 1, size->height - y - 1)[ch]
        // (*this)(x, size->height - y - 1)[ch]
        for (int ch = 0; ch < channels; ch++) {
          unsigned char tmp = (*this)(x, y)[ch];
          (*this)(x, y)[ch] = (*this)(size->height - y - 1, x)[ch];
          (*this)(size->height - y - 1, x)[ch]
              = (*this)(size->width - x - 1, size->height - y - 1)[ch];
          (*this)(size->width - x - 1, size->height - y - 1)[ch]
              = (*this)(x, size->height - y - 1)[ch];
          (*this)(x, size->height - y - 1)[ch] = tmp;

          std::swap(size->width, size->height);
        }
      }
    }
    break;

  case Image::CounterClockvise:
    break;
  }
}

} // namespace EngineToolkit