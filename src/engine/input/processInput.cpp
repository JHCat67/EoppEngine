#include "engine/input/processInput.hpp"

void ProcessInput::handleInput(bool &loopIsRunning) {
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            loopIsRunning = false;
        }
        if (event.type == SDL_EVENT_KEY_DOWN) {
            if (event.key.key == SDLK_ESCAPE) {
                loopIsRunning = false;
            }
        }
    }
}