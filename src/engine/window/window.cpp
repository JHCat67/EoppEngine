#include "engine/window/window.hpp"

Window::Window()
{
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "Error initializing SDL" << std::endl;
    }

    SDL_DisplayID displayID = SDL_GetPrimaryDisplay();
    const SDL_DisplayMode* mode = SDL_GetDesktopDisplayMode(displayID);

    window = SDL_CreateWindow("Eopp Engine", mode->w, mode->h, SDL_WINDOW_VULKAN);

    if (!window) {
        std::cout << "Error creating window" << SDL_GetError() << std::endl;
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}
