#pragma once

#include <iostream>
#include <SDL3/SDL.h>
#include <vulkan/vulkan.h>

class ScreenResolution;

class Window {
    public:
    int width, height;
    SDL_Window* window;
    Window();
    ~Window();
};