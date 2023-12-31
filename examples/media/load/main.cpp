#include <EngineToolkit/media/image.hpp>

#include <GL/gl.h>
#include <GLFW/glfw3.h>

#include <config.h>

using namespace EngineToolkit;

int main() {
  Image img(pathto("res/test.bmp").c_str());

  printf("%i %i\n", img.size->width, img.size->height);
  // img.flip(Image::Horizontally);
  // img.rotate(Image::Clockwise);

  // Initialize GLFW
  if (!glfwInit()) {
    return -1;
  }

  // Create tex windowed mode window and its OpenGL context
  GLFWwindow *window = glfwCreateWindow(600, 600, "Image Loading", NULL, NULL);
  if (!window) {
    glfwTerminate();
    return -1;
  }

  // Make the window's context current
  glfwMakeContextCurrent(window);

  GLuint tex;
  glGenTextures(1, &tex);
  glBindTexture(GL_TEXTURE_2D, tex);
  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img.size->x, img.size->y, 0, GL_RGB, GL_UNSIGNED_BYTE,
               img.data);

  // Set texture parameters
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

  // Enable texture mapping
  glEnable(GL_TEXTURE_2D);

  // Main rendering loop
  while (!glfwWindowShouldClose(window)) {
    // Clear the buffer
    glClear(GL_COLOR_BUFFER_BIT);

    glBindTexture(GL_TEXTURE_2D, tex);

    // Render tex quad with the texture
    glBegin(GL_QUADS);
    glTexCoord2f(0.0f, 0.0f);
    glVertex2f(-0.5f, -0.5f);
    glTexCoord2f(1.0f, 0.0f);
    glVertex2f(0.5f, -0.5f);
    glTexCoord2f(1.0f, 1.0f);
    glVertex2f(0.5f, 0.5f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    // Swap front and back buffers
    glfwSwapBuffers(window);

    // Poll for and process events
    glfwPollEvents();
  }

  // Cleanup
  glDeleteTextures(1, &tex);
  glfwTerminate();

  return 0;
}