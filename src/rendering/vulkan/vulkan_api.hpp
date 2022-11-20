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
    void create_command_buffer();
    
    void create_framebuffers();
    void create_sync_objects();

    void record_command_buffer(VkCommandBuffer commandBuffer, uint32_t imageIndex);
    
    vector<VkFramebuffer> swapChainFramebuffers;
    VkCommandPool commandPool;
    VkCommandBuffer commandBuffer;

    VkSemaphore imageAvailableSemaphore;
    VkSemaphore renderFinishedSemaphore;
    VkFence inFlightFence;

    VkRenderPass renderPass;
    VkPipelineLayout pipelineLayout;
    VkPipeline graphicsPipeline;

    VkExtent2D swapchain_extent;
    VkFormat swapchain_image_format;

    VkInstance instance;
    VkDebugUtilsMessengerEXT debugMessenger;

    VkSurfaceKHR surface;
    VkPhysicalDevice physical_device;
    VkDevice device;
    VkQueue graphics_queue, present_queue;
    VkSwapchainKHR swapchain;
    vector<VkImage> swapChainImages;
    vector<VkImageView> swapChainImageViews;
};
