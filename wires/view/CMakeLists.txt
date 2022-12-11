add_library(View user_interface.cpp user_interface.hpp window.cpp window.hpp)

target_include_directories(View PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS})
target_include_directories(View PUBLIC ${CMAKE_SOURCE_DIR}/wires)

target_link_libraries(View compile_flags ${SDL2_LIBRARIES})
