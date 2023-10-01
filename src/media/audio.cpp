#include <EngineToolkit/media/audio.hpp>

#define STB_VORBIS_NO_PUSHDATA_API
#include "ext/stb_vorbis.c"

#include <cctype>
#include <cstring>
#include <stdlib.h>
#include <string>

namespace EngineToolkit {

// Constructors & Destructor

Audio::Audio() {
  this->size = {0}, this->channels = 0;
  this->data = nullptr;
}

Audio::Audio(const char *path) { *this = load(path); }
Audio::Audio(Audio const &Audio) { *this = Audio; } // FIXME: may cause segfault
Audio::~Audio() {
  this->size = {0}, this->channels = 0, this->size = 0;

  free(this->data);
  this->data = nullptr;
}

// Assignment Operator

void Audio::operator=(const Audio Audio) {
  free(this->data);

  this->size = Audio.size;
  this->channels = Audio.channels;

  this->data = (typeof(this->data))malloc(this->size->x * this->size->y *
                                          this->channels);
  // TODO: error handling
  memcpy(this->data, Audio.data,
         Audio.size->x * Audio.size->y * Audio.channels);
}

// Other Operator

// unsigned char *Audio::operator()(uint32_t x, uint32_t y) const {
//   return &this->data[(std::min(x, this->size->x - 1) +
//                       std::min(y, this->size->y - 1) * this->size->x) *
//                      channels];
// }

// Functions (Static)

Audio Audio::load(const char *path) {
  Audio out;

  int channels, sampleRate;

  // Open the Vorbis file
  stb_vorbis *vorbis = stb_vorbis_open_filename(path, nullptr, nullptr);
  if (!vorbis) {
    printf("failed to open audio\n");
    return out;
  }

  // Get file information
  stb_vorbis_info info = stb_vorbis_get_info(vorbis);
  channels = info.channels;
  sampleRate = info.sample_rate;

  // Allocate memory for the audio data buffer
  std::vector<float> audioData;

  // Read and decode the audio data
  while (true) {
    float **output;
    int numSamples =
        stb_vorbis_get_samples_float_interleaved(vorbis, channels, *output, 1);

    if (numSamples == 0) {
      break; // End of file
    }

    for (int i = 0; i < numSamples * channels; ++i) {
      audioData.push_back(output[0][i]); // Store audio data in a buffer
    }
  }

  // Close the Vorbis file
  stb_vorbis_close(vorbis);

  return out;
}

} // namespace EngineToolkit