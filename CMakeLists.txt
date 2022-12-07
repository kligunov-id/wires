cmake_minimum_required(VERSION 3.20.0)
project(Wires VERSION 0.1.0)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/modules)
find_package(SDL2 REQUIRED)
include_directories(Wires ${SDL2_INCLUDE_DIRS})

add_executable(Wires main.cpp)
target_link_libraries(Wires ${SDL2_LIBRARIES})
