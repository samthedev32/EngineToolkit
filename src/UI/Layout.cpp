#pragma once

#include <EngineToolkit/UI/Layout.hpp>
#include <string.h>

namespace EngineToolkit {
namespace UI {

bool Layout::save(const char *path) {
  FILE *f = fopen(path, "wb");

  if (!f) {
    printf("Failed to create file!\n");
    return 1;
  }

  struct {
    char MAGIC[3] = {'u', 'i', 'l'};
    uint32_t table_size;
    uint32_t component_count;
  } header;

  header.table_size = table.size();
  header.component_count = components.size();

  // Write Header
  if (!fwrite(&header, sizeof(header), 1, f)) {
    printf("Failed to write header!\n");
    fclose(f);
    return 1;
  }

  // Write Table
  for (auto [key, value] : table) {
    int ret = 0;
    uint16_t size = value.size();
    ret += fwrite(&size, sizeof(uint16_t), 1, f);
    ret += fwrite(&key, sizeof(uint32_t), 1, f);
    ret += fwrite(value.data(), sizeof(char), size, f);

    if (ret != 2 + size) {
      printf("Failed to Write Table!\n");
      fclose(f);
      return 1;
    }
  }

  // Write Components
  for (auto c : components) {
    if (!fwrite(&c, sizeof(Component), 1, f)) {
      printf("Failed to write Component!\n");
      fclose(f);
      return 1;
    }
  }

  fclose(f);
  return 0;
}

Layout Layout::load(const char *path) {
  FILE *f = fopen(path, "rb");

  if (!f) {
    printf("Failed to open file!\n");
    return {};
  }

  // TODO: Load Binary
  struct {
    char MAGIC[3];
    uint32_t table_size;
    uint32_t component_count;
  } header;

  // Read Header
  if (!fread(&header, sizeof(header), 1, f)) {
    printf("Failed to read header!\n");
    fclose(f);
    return {};
  }

  if (strncmp(header.MAGIC, "uil", 3)) {
    printf("Invalid Header!\n");
    fclose(f);
    return {};
  }

  Layout out;

  // Read Table
  for (int i = 0; i < header.table_size; i++) {
    int ret = 0;

    uint16_t size = 0;
    ret += fread(&size, sizeof(uint16_t), 1, f);

    uint32_t key = 0;
    ret += fread(&key, sizeof(uint32_t), 1, f);

    char name[size];
    ret += fread(name, sizeof(char), size, f);

    if (ret != 2 + size) {
      printf("Failed to Read Table!\n");
      fclose(f);
      return {};
    }

    out.table[key] = name;
  }

  // Read Components
  for (int i = 0; i < header.component_count; i++) {
    Component c;
    if (!fread(&c, sizeof(Component), 1, f)) {
      printf("Failed to read Component!\n");
      fclose(f);
      return {};
    }

    out.components.push_back(c);
  }

  fclose(f);
  return out;
}

} // namespace UI
} // namespace EngineToolkit