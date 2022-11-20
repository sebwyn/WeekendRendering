cmake_minimum_required(VERSION 3.2)
project(rendering CXX)

add_subdirectory(lib/glfw)

add_subdirectory(vulkan)

set(SOURCE_FILES render_api.cpp render_api.hpp window.hpp window.cpp ${RENDER_API_SOURCE})
message(${SOURCE_FILES})

message("" ${GLFW_INCLUDE_DIRS})

include_directories(${GLFW_INCLUDE_DIRS} ${RENDER_API_INCLUDES})
add_library(rendering SHARED STATIC ${SOURCE_FILES})
target_link_libraries(rendering glfw ${GLFW_LIBRARIES} ${RENDER_API_LIBRARIES})

install(TARGETS rendering DESTINATION ${WEEKEND_RENDERING_INSTALL_LIB_DIR}/rendering)
install(FILES render_api.hpp window.hpp DESTINATION ${WEEKEND_RENDERING_INSTALL_INCLUDE_DIR}/rendering)
