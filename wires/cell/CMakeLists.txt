add_library(cell cell.cpp cell.hpp)

target_include_directories(cell PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(cell compile_flags)
