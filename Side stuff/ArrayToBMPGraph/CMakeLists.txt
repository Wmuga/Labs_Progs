cmake_minimum_required(VERSION 3.16)
project(ArrayToBMPGraph)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-static")

add_executable(ArrayToBMPGraph main.cpp bmp.h bmp.cpp)