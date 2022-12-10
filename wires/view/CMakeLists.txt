add_library(View view.cpp)

target_include_directories(View PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS})

target_link_libraries(View compile_flags ${SDL2_LIBRARIES})
