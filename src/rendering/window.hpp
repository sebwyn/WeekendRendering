#pragma once

#include <GLFW/glfw3.h>

class Window {
  public:
    Window(unsigned int width, unsigned int height);
    ~Window();

    void update();     
    bool closed();

    GLFWwindow* glfw_window() const { return window; }

    const char** get_vulkan_extensions(unsigned int* extension_count) const;
  private:
    GLFWwindow* window;
};
