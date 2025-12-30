#include "engine/window/window.hpp"
#include "engine/window/screenResolution.hpp"

Window::Window()
{
    ScreenResolution::getScreenResolution(width, height);

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        std::cout << "Error initializing SDL" << std::endl;
    }

    window = SDL_CreateWindow("Eopp Engine", width, height, SDL_WINDOW_VULKAN);

    if (!window) {
        std::cout << "Error creating window" << SDL_GetError() << std::endl;
    }
}

Window::~Window()
{
    SDL_DestroyWindow(window);
    SDL_Quit();
}
