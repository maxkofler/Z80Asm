cmake_minimum_required (VERSION 3.5)
project (Z80Asm)

include_directories(Log/include Argparser/include include)
add_subdirectory(Argparser)
add_subdirectory(libz80asm)
add_subdirectory(Log)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -static")

file (GLOB_RECURSE srcfiles "assembler/*.cpp")

add_executable (Z80Asm ${srcfiles})
target_link_libraries(Z80Asm libz80asm)
target_link_libraries(Z80Asm libargparser)
target_link_libraries(Z80Asm log)
add_dependencies(Z80Asm libargparser)
add_dependencies(Z80Asm libz80asm)
add_dependencies(Z80Asm log)