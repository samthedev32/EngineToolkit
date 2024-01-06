#include <EngineToolkit/window/x11.hpp>

#include <GL/gl.h>
#include <X11/XKBlib.h>
#include <X11/Xatom.h>
#include <X11/Xutil.h>

#define wmDeleteMessage XInternAtom(display, "WM_DELETE_WINDOW", False)

namespace EngineToolkit::internal {

X11Window::X11Window(std::string name, vec<2, uint32_t> size) : size(size) {
  // TODO: Error Handling
  display = XOpenDisplay(NULL);
  int screen = XDefaultScreen(display);

  // Chose Visual
  int attribList[] = {GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None};
  XVisualInfo *visualInfo = glXChooseVisual(display, screen, attribList);

  // Create GLXContext
  context = glXCreateContext(display, visualInfo, nullptr, GL_TRUE);

  // Create Window
  Colormap colorMap = XCreateColormap(display, XRootWindow(display, visualInfo->screen),
                                      visualInfo->visual, AllocNone);

  XSetWindowAttributes windowAttributes;
  windowAttributes.colormap = colorMap;
  windowAttributes.event_mask = ExposureMask | KeyPressMask;

  window = XCreateWindow(display, XRootWindow(display, visualInfo->screen), 0, 0, size->width,
                         size->height, 0, visualInfo->depth, InputOutput, visualInfo->visual,
                         CWColormap | CWEventMask, &windowAttributes);

  XMapWindow(display, window);
  XSelectInput(display, window, KeyPressMask | KeyReleaseMask);
  XStoreName(display, window, name.c_str());

  if (!glXMakeCurrent(display, window, context))
    printf("failed to make context current");

  //   if (!gladLoadGL())
  // printf("failed to init glad");

  //   std::cout << "OpenGL Version: " << GLVersion.major << "." << GLVersion.minor << std::endl;
  // #endif

  deltaTime = -1;
}

X11Window::~X11Window() {
  glXMakeCurrent(display, None, nullptr);
  glXDestroyContext(display, context);
  XDestroyWindow(display, window);
  XCloseDisplay(display);
}

bool X11Window::update(vec<3, float> color) {
  // Handle First Update
  if (deltaTime == -1)
    now = 0;

  // Timing
  past = now;
  now = 0;
  deltaTime = (float)(now - past) / 1000;

  // Update Window
  glXSwapBuffers(display, window);

  // Update Screen
  //   glClearColor(color->red, color->green, color->blue);
  glClear(GL_COLOR_BUFFER_BIT);

  // Poll Events
  XEvent event;
  while (XCheckMaskEvent(display, ExposureMask | KeyPressMask, &event)) {
    switch (event.type) {
    case Expose: {
      size = {event.xexpose.width, event.xexpose.height};
      // glXSwapBuffers(display, window);
      break;
    }
    case KeyPress: {
      char buffer[10];
      int count = XLookupString(&event.xkey, buffer, sizeof(buffer), nullptr, nullptr);
      printf("Key Pressed: %c\n", buffer[0]);
      break;
    }
    case KeyRelease: {
      char buffer[10];
      int count = XLookupString(&event.xkey, buffer, sizeof(buffer), nullptr, nullptr);
      printf("Key Released: %c\n", buffer[0]);
      break;
    }
    case ClientMessage: {
      if (event.xclient.data.l[0] == wmDeleteMessage) {
        printf("Closing Window\n");
        shouldClose = true;
      }
      break;
    }
    }
  }

  return !shouldClose;
}

void X11Window::kill(bool sure) {
  shouldClose = sure;
}

bool X11Window::key(std::string k) {
  if (k == "lmouse" || k == "left")
    return mouseState[0];
  else if (k == "rmouse" || k == "right")
    return mouseState[1];
  else if (k == "mmouse" || k == "middle")
    return mouseState[2];
  else if (k == "mouse")
    return (key("left") || key("right"));
}

} // namespace EngineToolkit::internal