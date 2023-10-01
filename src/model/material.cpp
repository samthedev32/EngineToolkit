#include <EngineToolkit/model/material.hpp>
#include <cstdio>
#include <cstring>

namespace EngineToolkit {

Material::MTL Material::load(const char *path) {
  MTL out;

  // Open File

  FILE *f = fopen(path, "r");

  if (!f) {
    printf("failed to open file\n");
    return out;
  }

  // Read File

  std::string cursor = "";

  char line[256];
  while (fgets(line, sizeof(line), f)) {
    char index[8], data[128];
    int c = sscanf(line, "%7s %[^\n]s", index, data);

    if (c == 2) {
      if (!strcmp(index, "newmtl")) {
        // Define New Material
        char name[64];
        int c = sscanf(data, "%63s", name);
        if (c == 1 && out.count(name) == 0) {
          out.insert(name, {});
          cursor = name;
        } else
          printf("material already exists\n");
      } else if (!strcmp(index, "Ka")) {
        // Ambient Color
        vec<3> Ka;
        sscanf(data, "%f %f %f", &Ka->r, &Ka->g, &Ka->b);
      } else if (!strcmp(index, "Kd")) {
        // Diffuse Color
        vec<3> Kd;
        sscanf(data, "%f %f %f", &Kd->r, &Kd->g, &Kd->b);
      } else if (!strcmp(index, "Ks")) {
        // Specular Color
        vec<3> Ks;
        sscanf(data, "%f %f %f", &Ks->r, &Ks->g, &Ks->b);
      }
    }
  }

  return out;
}

} // namespace EngineToolkit