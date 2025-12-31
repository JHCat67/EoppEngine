#include <X11/Xlib.h>
#include "engine/window/screenResolution.hpp"

void ScreenResolution::getScreenResolution(int& width, int& height) {
    Display* display = XOpenDisplay(NULL);
    Screen* screen = DefaultScreenOfDisplay(d);

    width = screen.width;
    height = screen.height;
}