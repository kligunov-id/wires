add_library(view user_interface.cpp user_interface.hpp window.cpp window.hpp event_queue.hpp event_queue.cpp)

target_include_directories(view PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS})
target_include_directories(view PUBLIC ${CMAKE_SOURCE_DIR}/wires)

target_link_libraries(view compile_flags ${SDL2_LIBRARIES} cell)
