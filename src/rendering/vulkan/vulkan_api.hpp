#pragma once

#include <istream>
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
    ~VulkanApi() override;

    void draw() override;

    string info() override;
private:
    const Window& window;

    //Api state (instance, device, and queues)
    void init_instance(const Window& window);
    void setup_debug_messenger();

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;

    QueueFamilyIndices find_queue_families(const VkPhysicalDevice& physical_device);
    SwapChainSupportDetails query_swapchain_support(const VkPhysicalDevice& physical_device);

    void init_physical_device();
    void init_device();

    VkSurfaceKHR surface;
    VkPhysicalDevice physical_device;
    VkDevice device;
    VkQueue graphics_queue, present_queue;

    //Swapchain
    void create_swapchain();
    void create_swapchain_image_views();
    void recreate_swapchain();
    void cleanup_swapchain();

    VkExtent2D swapchain_extent;
    VkFormat swapchain_image_format;
    vector<VkImage> swapChainImages;
    vector<VkImageView> swapChainImageViews;
    VkSwapchainKHR swapchain;


    //Render Pipeline state
    VkShaderModule create_shader_module(const vector<char>& code);
    void create_graphics_pipeline();
    void create_render_pass();
    void create_framebuffers();

    vector<VkFramebuffer> swapChainFramebuffers;
    VkRenderPass renderPass;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;

    //Drawing State
    void record_command_buffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
    const uint32_t MAX_FRAMES_IN_FLIGHT = 2;
    uint32_t current_frame = 0;

    void create_command_pool();
    void create_command_buffers();

    vector<VkCommandBuffer> command_buffers;
    VkCommandPool commandPool;
    
    void create_sync_objects();

    vector<VkSemaphore> image_available_semaphores;
    vector<VkSemaphore> render_finished_semaphores;
    vector<VkFence> in_flight_fences;
};
