#include "engine/window/screenResolution.hpp"

void ScreenResolution::getScreenResolution(int &width, int &height)
{
    RECT desktop;

    const HWND hDesktop = GetDesktopWindow();

    GetWindowRect(hDesktop, &desktop);

    width = desktop.right;
    height = desktop.bottom;
}