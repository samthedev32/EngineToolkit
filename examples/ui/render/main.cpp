#include <EngineToolkit/UI/ui.hpp>

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

using namespace EngineToolkit;

// Basic UI Renderer
class Render {
public:
  Render(const char *title, vec<2, uint32_t> size = {720, 480});
  ~Render();

  bool update(vec<3, float> clearColor = {});
  void draw(const UI::Layout &layout);

protected: // no need to be `protected`, but is great separation
  vec<2, uint32_t> size;

private:
  GLFWwindow *window = nullptr;
  static void callback_resize(GLFWwindow *window, int w, int h);
};

int main() {
  // Manually Build Layout (layout builder is in a different example)
  UI::Layout layout;

  // Init Window & Renderer
  Render render("UI Rendering Example");

  // Main rendering loop
  while (render.update()) {
    // glBindTexture(GL_TEXTURE_2D, tex);

    // Render tex quad with the texture
    glBegin(GL_QUADS);
    // glTexCoord2f(0.0f, 1.0f);
    glVertex2f(-0.5f, -0.5f);
    // glTexCoord2f(1.0f, 1.0f);
    glVertex2f(0.5f, -0.5f);
    // glTexCoord2f(1.0f, 0.0f);
    glVertex2f(0.5f, 0.5f);
    // glTexCoord2f(0.0f, 0.0f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();
  }

  return 0;
}

// ---- Render Class Implementation

Render::Render(const char *title, vec<2, uint32_t> size) {
  // Initialize GLFW
  if (!glfwInit()) {
    throw std::runtime_error("Failed to initialize GLFW");
  }

  // Create Window
  window = glfwCreateWindow(size->width, size->height, title, nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    throw std::runtime_error("Failed to Create Window");
  }

  glfwMakeContextCurrent(window);

  // Set Resize Callback
  glfwSetWindowUserPointer(window, this);
  glfwSetFramebufferSizeCallback(window, callback_resize);

  // GLuint tex;
  // glGenTextures(1, &tex);
  // glBindTexture(GL_TEXTURE_2D, tex);
  // glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.size->x, img.size->y, 0, GL_RGB,
  // GL_UNSIGNED_BYTE,
  //  img.data);

  // Set texture parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  // Enable texture mapping
  glEnable(GL_TEXTURE_2D);
}

Render::~Render() {
  // glDeleteTextures(1, &tex);
  if (window)
    glfwDestroyWindow(window);
  glfwTerminate();
}

bool Render::update(vec<3, float> clearColor) {
  // Update Framebuffer
  glfwSwapBuffers(window);

  // Clear Screen
  glClearColor(clearColor->red, clearColor->green, clearColor->blue, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT);

  // Poll events
  glfwPollEvents();

  return !glfwWindowShouldClose(window);
}

void Render::draw(const UI::Layout &layout) {
  // TODO
}

void Render::callback_resize(GLFWwindow *window, int w, int h) {
  auto *self = (Render *)glfwGetWindowUserPointer(window);
  if (self) {
    glViewport(0, 0, w, h);
    self->size = {w, h};
  }
}