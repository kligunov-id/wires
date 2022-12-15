add_subdirectory(view)
add_subdirectory(controller)

add_executable(wires main.cpp)

target_include_directories(wires PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(wires compile_flags controller)
