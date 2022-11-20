#pragma once

#include <vector>
#include <optional>

#include <vulkan/vulkan.h>

#include "../render_api.hpp"
#include "../window.hpp"

struct QueueFamilyIndices {
    optional<uint32_t> graphics_family;
    optional<uint32_t> present_family;

    QueueFamilyIndices() = default;

    bool is_complete() {
        return graphics_family.has_value() && present_family.has_value();
    }
};

struct SwapChainSupportDetails {
    VkSurfaceCapabilitiesKHR capabilities;
    vector<VkSurfaceFormatKHR> formats;
    vector<VkPresentModeKHR> present_modes;
};

class VulkanApi : public RenderApi {
public:
    VulkanApi(const Window& window);

    void draw() override;

    ~VulkanApi() override;

    string info() override;
private:
    void draw_frame();

    void init_instance(const Window& window);
    void setup_debug_messenger();

    QueueFamilyIndices find_queue_families(const VkPhysicalDevice& physical_device);
    SwapChainSupportDetails query_swapchain_support(const VkPhysicalDevice& physical_device);

    void init_physical_device();
    void init_device();

    void init_swapchain(const Window& window);
    void init_image_views();

    VkShaderModule create_shader_module(const vector<char>& code);
    void create_graphics_pipeline();
    void create_render_pass();

    void create_command_pool();
    void create_command_buffers();
    
    void create_framebuffers();
    void create_sync_objects();

    void record_command_buffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
    
    const uint32_t MAX_FRAMES_IN_FLIGHT = 2;
    uint32_t current_frame = 0;

    vector<VkCommandBuffer> command_buffers;
    vector<VkSemaphore> image_available_semaphores;
    vector<VkSemaphore> render_finished_semaphores;
    vector<VkFence> in_flight_fences;

    VkRenderPass renderPass;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;

    VkCommandPool commandPool;

    vector<VkFramebuffer> swapChainFramebuffers;
    VkExtent2D swapchain_extent;
    VkFormat swapchain_image_format;
    vector<VkImage> swapChainImages;
    vector<VkImageView> swapChainImageViews;
    VkSwapchainKHR swapchain;

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;

    VkSurfaceKHR surface;
    VkPhysicalDevice physical_device;
    VkDevice device;
    VkQueue graphics_queue, present_queue;
};
