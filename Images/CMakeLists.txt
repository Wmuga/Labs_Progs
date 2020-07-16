cmake_minimum_required(VERSION 3.16)
project(Image)

set(CMAKE_CXX_STANDARD 17)

add_executable(Image main.cpp digits_bool_array.h bmp_writer.h bmp_writer.cpp)