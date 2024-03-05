#pragma once

#include <stdexcept>
#include <string>

#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <EngineToolkit/math/vec.hpp>

// NOTE: every function is inline so they don't trigger clangd warnings,
// they don't have to be and probably shouldn't be

enum DrawMode { FILL, LINE, POINT };

// Simple Window Class
class Window {
public:
  inline Window(std::string title);
  inline ~Window();

  // Update Window & Clear Screen
  inline bool update(vec<3> clearColor = {});

  // Close Window
  inline void exit(bool sure = true) {
    glfwSetWindowShouldClose(window, sure);
  }

  // Set Draw Mode
  inline void setMode(DrawMode drawMode = FILL);

  // Set Draw Color
  inline void setColor(vec<3> color = {}) const;

  // Render Quad
  inline void quad(vec<2> center, vec<2> size) const;

public:
  vec<2, int> size;

private:
  GLFWwindow *window{};
};

Window::Window(std::string title) {
  // Init Window
  if (!glfwInit()) {
    throw std::runtime_error("Failed to initialize GLFW\n");
  }

  window = glfwCreateWindow(720, 480, title.c_str(), nullptr, nullptr);
  if (!window) {
    glfwTerminate();
    throw std::runtime_error("Failed to create Window\n");
  }

  glfwMakeContextCurrent(window);

  // Set half refresh rate (30 fps at a 60 hz monitor)
  // more than enough for what we're using this for
  glfwSwapInterval(2);
}

Window::~Window() {
  if (window)
    // not required, but good practice
    glfwDestroyWindow(window);
  glfwTerminate();
}

bool Window::update(vec<3> clearColor) {
  // Update Framebuffer
  glfwSwapBuffers(window);

  // Poll Window Events
  glfwPollEvents();

  // Update Window Size every frame
  // not optimal, but this is only made to show UI building
  glfwGetFramebufferSize(window, &size->width, &size->height);
  glViewport(0, 0, size->width, size->height);

  // Clear Screen
  glClearColor(clearColor->red, clearColor->green, clearColor->blue, 1);
  glClear(GL_COLOR_BUFFER_BIT);

  return !glfwWindowShouldClose(window);
}

void Window::setMode(DrawMode drawMode) {
  switch (drawMode) {
  default:
  case FILL:
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    break;

  case LINE:
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    break;

  case POINT:
    glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
    break;
  }
}

void Window::setColor(vec<3> color) const {
  glColor3f(color->red, color->green, color->blue);
}

void Window::quad(vec<2> center, vec<2> size) const {
  glBegin(GL_QUADS);
  glVertex2f(center->x - size->x / 2.0f, center->y - size->y / 2.0f);
  glVertex2f(center->x - size->x / 2.0f, center->y + size->y / 2.0f);
  glVertex2f(center->x + size->x / 2.0f, center->y + size->y / 2.0f);
  glVertex2f(center->x + size->x / 2.0f, center->y - size->y / 2.0f);
  glEnd();
}