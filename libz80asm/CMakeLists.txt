cmake_minimum_required (VERSION 3.5)

include_directories(./log)
include_directories(./include)

file (GLOB_RECURSE libz80files "./*cpp")
add_library(libz80asm STATIC ${libz80files})
target_link_libraries(libz80asm log)