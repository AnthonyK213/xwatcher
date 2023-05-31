// #define DEBUG
#include <X11/X.h>
#include <X11/Xlib.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
#ifdef DEBUG
  const char *type[37] = {0};
  type[2] = "KeyPress";
  type[3] = "KeyRelease";
  type[4] = "ButtonPress";
  type[5] = "ButtonRelease";
  type[6] = "MotionNotify";
  type[7] = "EnterNotify";
  type[8] = "LeaveNotify";
  type[9] = "FocusIn";
  type[10] = "FocusOut";
  type[11] = "KeymapNotify";
  type[12] = "Expose";
  type[13] = "GraphicsExpose";
  type[14] = "NoExpose";
  type[15] = "VisibilityNotify";
  type[16] = "CreateNotify";
  type[17] = "DestroyNotify";
  type[18] = "UnmapNotify";
  type[19] = "MapNotify";
  type[20] = "MapRequest";
  type[21] = "ReparentNotify";
  type[22] = "ConfigureNotify";
  type[23] = "ConfigureRequest";
  type[24] = "GravityNotify";
  type[25] = "ResizeRequest";
  type[26] = "CirculateNotify";
  type[27] = "CirculateRequest";
  type[28] = "PropertyNotify";
  type[29] = "SelectionClear";
  type[30] = "SelectionRequest";
  type[31] = "SelectionNotify";
  type[32] = "ColormapNotify";
  type[33] = "ClientMessage";
  type[34] = "MappingNotify";
  type[35] = "GenericEvent";
  type[36] = "LASTEvent";
#endif

  Display *display;
  int screen;
  Window root, window;

  display = XOpenDisplay(NULL);

  if (!display) {
    err(1, "Could not open display.\n");
  }

  screen = DefaultScreen(display);
  root = RootWindow(display, screen);
  window = DefaultRootWindow(display);

  if (window < 0) {
    err(1, "Failed to obtain the root windows Id of the default screen \
given display.\n");
  }

  XSelectInput(display, window, ExposureMask | StructureNotifyMask);
  XMapWindow(display, window);
  XFlush(display);

  XEvent event;
  for (;;) {
    system("~/.xrandr-changed");
    XNextEvent(display, &event);
#ifdef DEBUG
    printf("%s\n", type[event.type]);
#endif
  }

  return 0;
}
