cmake_minimum_required(VERSION 3.2)
project(weekend_rendering_tests)

add_subdirectory(lib/googletest)

include_directories(${WEEKEND_RENDERING_HEADERS_DIR})
include_directories(lib/googletest/googletest/include)

set(SOURCE_FILES main.cpp src/weekend_rendering.cpp)

add_executable(weekend_rendering_tests ${SOURCE_FILES})
target_link_libraries(weekend_rendering_tests rendering gtest)
install(TARGETS weekend_rendering_tests DESTINATION bin)

