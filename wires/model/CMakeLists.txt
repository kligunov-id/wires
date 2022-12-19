add_library(model field.cpp field.hpp)

target_include_directories(model PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(model PUBLIC ${CMAKE_SOURCE_DIR}/wires)

target_link_libraries(model compile_flags cell)
