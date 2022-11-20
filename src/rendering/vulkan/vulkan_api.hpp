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

    ~VulkanApi() override;

    string info() override;
private:
    void init_instance(const Window& window);

    QueueFamilyIndices find_queue_families(const VkPhysicalDevice& physical_device);
    SwapChainSupportDetails query_swapchain_support(const VkPhysicalDevice& physical_device);

    tuple<QueueFamilyIndices, SwapChainSupportDetails> init_physical_device();
    void init_device(const QueueFamilyIndices& indices);
    void init_swapchain(const Window& window, const QueueFamilyIndices& indices, const SwapChainSupportDetails& swapchain_support);


    VkInstance instance;
    VkSurfaceKHR surface;
    VkPhysicalDevice physical_device;
    VkDevice device;
    VkQueue graphics_queue, present_queue;
    VkSwapchainKHR swapchain;
};
