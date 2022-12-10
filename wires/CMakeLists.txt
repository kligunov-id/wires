add_subdirectory(view)

add_executable(wires main.cpp)

target_include_directories(wires PUBLIC ${SDL2_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(wires ${SDL2_LIBRARIES} compile_flags View)
