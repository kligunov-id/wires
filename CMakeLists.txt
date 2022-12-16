cmake_minimum_required(VERSION 3.20.0)
project(Wires VERSION 0.1.0)

add_library(compile_flags INTERFACE)
target_compile_features(compile_flags INTERFACE cxx_std_20)

set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/modules)
find_package(SDL2 REQUIRED)

add_subdirectory(wires)
