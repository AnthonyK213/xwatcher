#include <X11/Xlib.h>
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
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

  XWindowAttributes xwAttr;
  int width = 0;
  int height = 0;

  for (;;) {
    Status ret = XGetWindowAttributes(display, window, &xwAttr);

    if (width != xwAttr.width || height != xwAttr.height) {
      width = xwAttr.width;
      height = xwAttr.height;
      system("~/.xrandr-changed");
    }

    sleep(1);
  }

  return 0;
}
