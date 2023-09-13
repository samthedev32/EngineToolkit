#include <EngineToolkit/mesh/mesh.hpp>

#include <cstdint>
#include <cstdio>
#include <cstring>

namespace EngineToolkit {

Model Model::load(const char *path) {
  FILE *f = fopen(path, "r");

  if (!f) {
    fprintf(stderr, "Failed to open file\n");
    return {};
  }

  std::vector<vec3> vertices;
  std::vector<vec2> texCoords;
  std::vector<vec3> normals;

  Model model;

  // Load Model
  char line[256];
  while (fgets(line, sizeof(line), f)) {
    char index[8];
    char data[129];
    int c = sscanf(line, "%7s %[^\n]s", index, data);

    if (c == 2) {
      if (!strcmp(index, "v")) {
        vec3 vertex;
        sscanf(data, "%f %f %f", &vertex.x, &vertex.y, &vertex.z);
        vertices.push_back(vertex);
      } else if (!strcmp(index, "vt")) {
        vec2 texCoord;
        sscanf(data, "%f %f %*f", &texCoord.x, &texCoord.y);
        texCoords.push_back(texCoord);
      } else if (!strcmp(index, "vn")) {
        vec3 normal;
        sscanf(data, "%f %f %f", &normal.x, &normal.y, &normal.z);
        normals.push_back(normal);
      } else if (!strcmp(index, "f")) {
        int v[4], vt[4], vn[4];
        char part[4][128];
        int parts =
            sscanf(data, "%s %s %s %s", part[0], part[1], part[2], part[3]);

        for (int i = 0; i < parts; i++) {
          if (sscanf(part[i], "%i/%i/%i", &v[i], &vt[i], &vn[i]) != 3)
            if (sscanf(part[i], "%i//%i", &v[i], &vn[i]) != 2)
              if (sscanf(part[i], "%i/%i", &v[i], &vt[i]) != 2)
                if (sscanf(part[i], "%i", &v[i]) != 1) {
                  printf("Failed to read Face Line\n");
                  parts = 0;
                }
        }

        if (parts != 3)
          fprintf(stderr, "Face is not a Tri (%i)\n", parts);
        else {
          // TODO: duplicate face optimization
          for (int i = 0; i < 3; i++) {
            Vertex vertex;
            vertex.position = vertices[v[i] - 1];
            vertex.texCoord = texCoords[vt[i] - 1];

            model.vertices.push_back(vertex);
            model.indices.push_back(model.vertices.size() - 1);
          }
        }
      }
    }
  }

  if (model.indices.size() < 3) {
    fprintf(stderr, "No triangles were loaded\n");
  }

  return model;
}

} // namespace EngineToolkit