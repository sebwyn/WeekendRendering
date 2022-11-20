#include "render_api.hpp"
#include "vulkan/vulkan_api.hpp"

RenderApi* create_render_api(const Window& window) {
  return (RenderApi*)new VulkanApi(window);
}
