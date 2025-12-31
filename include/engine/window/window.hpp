#pragma once

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_video.h>
#include <vulkan/vulkan.h>

class Window {
    public:
    SDL_Window* window;
    Window();
    ~Window();
};