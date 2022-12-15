add_library(controller game.cpp game.hpp)

target_include_directories(controller PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${SDL2_INCLUDE_DIRS})
target_include_directories(controller PUBLIC ${CMAKE_SOURCE_DIR}/wires)

target_link_libraries(controller compile_flags ${SDL2_LIBRARIES} view)
