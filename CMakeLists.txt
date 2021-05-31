cmake_minimum_required (VERSION 3.5)
project (Z80Asm)

include_directories(Argparser/include include)
add_subdirectory(Argparser)
add_subdirectory(libasm)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -static")

file (GLOB_RECURSE srcfiles "assembler/*.cpp")

add_executable (Z80Asm ${srcfiles})
target_link_libraries(Z80Asm libasm)
target_link_libraries(Z80Asm libargparser)
add_dependencies(Z80Asm libargparser)
add_dependencies(Z80Asm libasm)