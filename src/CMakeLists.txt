cmake_minimum_required(VERSION 3.2)
project(game)

add_subdirectory(rendering)

set(SOURCE_FILES main.cpp)

add_executable(game ${SOURCE_FILES})
target_link_libraries(game rendering)
install(TARGETS game DESTINATION ${WEEKEND_RENDERING_INSTALL_BIN_DIR})
