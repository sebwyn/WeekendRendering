cmake_minimum_required(VERSION 3.2)
project(rendering CXX)

find_package(Vulkan REQUIRED FATAL_ERROR)

message(${Vulkan_LIBRARIES})
message(${Vulkan_INCLUDE_DIRS})

set(RENDER_API_SOURCE vulkan/vulkan_api.cpp vulkan/vulkan_api.hpp PARENT_SCOPE)
set(RENDER_API_INCLUDES ${Vulkan_INCLUDE_DIRS} PARENT_SCOPE)
set(RENDER_API_LIBRARIES ${Vulkan_LIBRARIES} PARENT_SCOPE)
