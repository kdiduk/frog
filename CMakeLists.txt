# MIT License

cmake_minimum_required(VERSION 3.13)

project(frog VERSION 0.0.1 DESCRIPTION "C++ 2D game developlent library")

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)


set(FROG_TARGET frog)

# find SDL2 library
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)

set(CMAKE_CXX_STANDARD 17)

add_library(${FROG_TARGET} SHARED "")
target_link_libraries(${FROG_TARGET} ${SDL2_LIBRARIES})

target_compile_options(${FROG_TARGET} PRIVATE -Wall -Wextra -pedantic)

target_include_directories(${FROG_TARGET} PUBLIC include)

# NOTE: Linux only
target_include_directories(${FROG_TARGET} PRIVATE "/usr/include/SDL2")

add_subdirectory(src)

# EOF
