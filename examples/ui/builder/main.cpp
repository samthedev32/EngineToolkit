#include "EngineToolkit/UI/Layout.hpp"
#include "EngineToolkit/UI/LayoutPrototype.hpp"
#include <EngineToolkit/UI/ui.hpp>

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <ctime>

using namespace EngineToolkit;

void asd(UI::LayoutPrototype lp);

int main() {
  // UI::LayoutPrototype prototype;

  // prototype.Box([&] {
  //   UI::LayoutPrototype p;

  //   p.Element("card");
  //   p.Element("card");
  //   p.Element("card");

  //   return p;
  // }());

  // prototype.Element("card");
  // prototype.Element("carda");
  // prototype.Element("card");
  // prototype.Element("card");

  // prototype.Box(NULL, UI::Modifier().size(1));

  // prototype.Column([] {
  //   UI::LayoutPrototype l;
  //   l.Button();
  //   return l;
  // });

  // UI::Layout layout = prototype.build();
  // layout.save("test.layout");

  UI::Layout layout = UI::Layout::load("test.layout");

  // TODO

  printf("%zu\n", layout.table.size());

  // Init Window
  if (!glfwInit()) {
    printf("Failed to initialize GLFW\n");
    return 1;
  }

  GLFWwindow *window = glfwCreateWindow(720, 480, "UI Builder Example", nullptr, nullptr);
  if (!window) {
    printf("Failed to create Window\n");
    glfwTerminate();
    return 1;
  }

  glfwMakeContextCurrent(window);
  glfwSwapInterval(2);

  int seed = time(0);

  // Set Draw Mode to Wireframe
  // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

  // Main Loop
  while (!glfwWindowShouldClose(window)) {
    // Update Framebuffer
    glfwSwapBuffers(window);

    // Update Window Size every update
    // not practical, but this is not a best practices example
    vec<2, int> wsize;
    glfwGetFramebufferSize(window, &wsize->width, &wsize->height);
    glViewport(0, 0, wsize->width, wsize->height);

    // Clear Screen
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    srand(seed);

    glColor3f(1.0f, 1.0f, 1.0f);

    const vec<2, float> center = {0.0f, 0.0f};
    const vec<2, float> size = {1.0f, 1.0f};

    // Render tex quad with the texture
    glBegin(GL_QUADS);
    // glTexCoord2f(0.0f, 1.0f);
    glVertex2f(center->x - size->x / 2.0f, center->y - size->y / 2.0f);
    // glTexCoord2f(1.0f, 1.0f);
    glVertex2f(center->x - size->x / 2.0f, center->y + size->y / 2.0f);
    // glTexCoord2f(1.0f, 0.0f);
    glVertex2f(center->x + size->x / 2.0f, center->y + size->y / 2.0f);
    // glTexCoord2f(0.0f, 0.f);
    glVertex2f(center->x + size->x / 2.0f, center->y - size->y / 2.0f);
    glEnd();

    // Draw UI Bounding Rects
    for (auto c : layout.components) {

      srand(c.typeID * 9686);

      float x = (center->x - size->x / 2.0f) + c.position->x * size->x;
      float y = (center->y + size->y / 2.0f) - c.position->y * size->y;
      // NOTE: y is different from x since gpus start from the left-bottom corner
      // and UI in general from the top-left
      float w = c.size->width;
      float h = c.size->height;

      // Generate Color for each UI element
      // since we set the same seed every frame,
      // the color will stay the same (per component)
      glColor3f((rand() % 100) / 100.0f, (rand() % 100) / 100.0f, (rand() % 100) / 100.0f);

      // Render tex quad with the texture
      glBegin(GL_QUADS);
      // glTexCoord2f(0.0f, 1.0f);
      glVertex2f(x - w / 2, y - h / 2);
      // glTexCoord2f(1.0f, 1.0f);
      glVertex2f(x - w / 2, y + h / 2);
      // glTexCoord2f(1.0f, 0.0f);
      glVertex2f(x + w / 2, y + h / 2);
      // glTexCoord2f(0.0f, 0.0f);
      glVertex2f(x + w / 2, y - h / 2);
      glEnd();
    }

    // Poll Window Events
    glfwPollEvents();
  }

  if (window)
    // not required but considered good practice
    glfwDestroyWindow(window);
  glfwTerminate();
  return 0;
}