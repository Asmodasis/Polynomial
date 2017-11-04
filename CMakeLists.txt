
cmake_minimum_required(VERSION 3.2)

project(Proj2)

set(VERSION_MAJOR "3")
set(VERSION_MINOR "7")
set(VERSION_PATCH "2")
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

set(OUTPUT "Polynomial")
set(DRIVER "poly_class")
set(CMAKE_CXX_COMPILER  "C:/MinGW/bin/g++")
set(CMAKE_CXX_FLAGS "-pedantic -std=c++11 -Wall -Wextra")

add_library(${PROJECT_NAME} SHARED ${OUTPUT}.h ${OUTPUT}.cpp ${DRIVER}.cpp)

add_compile_options(${CMAKE_CXX_COMPILER_ABI} ${CMAKE_CXX_FLAGS_DEBUG})

add_executable(${OUTPUT} ${OUTPUT}.cpp ${DRIVER}.cpp)

#add_custom_command(
#      TARGET ${OUTPUT}.exe
#      COMMAND echo -E "2"
#
#)