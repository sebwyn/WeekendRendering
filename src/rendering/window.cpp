#include "window.hpp"
#include "GLFW/glfw3.h"

Window::Window(unsigned int width, unsigned int height) {
  glfwInit();  

  glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
  //glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

  window = glfwCreateWindow(width, height, "Rendering Window", nullptr, nullptr);
}

Window::~Window(){
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::update() {
  glfwPollEvents();
}     

bool Window::closed() {
  return glfwWindowShouldClose(window);
}

const char** Window::get_vulkan_extensions(unsigned int* extension_count) const {
  return glfwGetRequiredInstanceExtensions(extension_count);
}
