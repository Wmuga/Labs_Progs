cmake_minimum_required(VERSION 3.16)
project(StudPractice)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libstdc++ -static-libgcc")

add_executable(StudPractice main.cpp)