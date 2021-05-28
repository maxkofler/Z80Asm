cmake_minimum_required (VERSION 3.5)
project (Z80Asm)

include_directories(Argparser/include)
add_subdirectory(Argparser)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -static")
set (source_dir "${PROJECT_SOURCE_DIR}/src/")

file (GLOB_RECURSE srcfiles "${source_dir}/*.cpp")

add_executable (Z80Asm.out ${srcfiles})
target_link_libraries(Z80Asm.out libargparser)
add_dependencies(Z80Asm.out libargparser)