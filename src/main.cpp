#include <iostream>
#include <SDL3/SDL.h>
#include <vulkan/vulkan.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/quaternion.hpp>
#include "engine/window/window.hpp"
#include "engine/input/processInput.hpp"
#include "engine/vulkan/createInstance.hpp"

int main() {
    bool loopIsRunning = true;
    Window window; // Creates a window
    CreateInstance createInstance;
    ProcessInput handleInput; // Creates a input loop which handles all incoming keypresses.

    createInstance.createInstance(&window);

    while (loopIsRunning) {
        Uint64 start = SDL_GetPerformanceCounter();

        handleInput.handleInput(loopIsRunning);

        Uint64 end = SDL_GetPerformanceCounter();

        float elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        SDL_Delay(floor(16.666f - elapsedMS));
    }

    return 0;
}