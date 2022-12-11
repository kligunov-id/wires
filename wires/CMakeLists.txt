add_subdirectory(view)

add_executable(wires main.cpp)

target_include_directories(wires PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(wires compile_flags view)
