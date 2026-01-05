#pragma once

#include <SDL3/SDL.h>
#include <vulkan/vulkan.h>

class Window;

class CreateInstance {
    public:
    static void createInstance(Window* window);
    private:
    static VkInstance instance;
};