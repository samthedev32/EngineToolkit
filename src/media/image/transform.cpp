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

void Image::rotate(typeof(Image::Clockwise) direction) {
  switch (direction) {
  default:
  case Image::Clockwise:
    for (uint32_t x = 0; x < size->width / 2; x++) {
      for (uint32_t y = 0; y < size->height / 2; y++) {
        if ((size->width % 2 && x == size->width / 2)
            || (size->height % 2 && y == size->height / 2))
          continue;

        unsigned char *a = (*this)(x, y);
        unsigned char *b = (*this)(size->height - y - 1, x);
        unsigned char *c = (*this)(size->width - x - 1, size->height - y - 1);
        unsigned char *d = (*this)(y, size->width - x - 1);
        for (int ch = 0; ch < channels; ch++) {
          unsigned char tmp = a[ch];
          a[ch] = b[ch];
          b[ch] = c[ch];
          c[ch] = d[ch];
          d[ch] = tmp;
        }
      }
    }
    std::swap(size->width, size->height);
    break;

  case Image::CounterClockwise:
    for (uint32_t x = 0; x < size->width / 2; x++) {
      for (uint32_t y = 0; y < size->height / 2; y++) {
        unsigned char *a = (*this)(y, x);
        unsigned char *b = (*this)(x, size->height - y - 1);
        unsigned char *c = (*this)(size->height - y - 1, size->width - x - 1);
        unsigned char *d = (*this)(size->width - x - 1, y);
        for (int ch = 0; ch < channels; ch++) {
          unsigned char tmp = a[ch];
          a[ch] = b[ch];
          b[ch] = c[ch];
          c[ch] = d[ch];
          d[ch] = tmp;
        }
      }
    }
    std::swap(size->width, size->height);
    break;
  }
}

} // namespace EngineToolkit