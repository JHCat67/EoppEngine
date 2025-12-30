#pragma once

#include <SDL3/SDL.h>

class ProcessInput {
    public:
    SDL_Event event;
    void handleInput(bool& loopIsRunning);
};