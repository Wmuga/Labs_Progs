cmake_minimum_required(VERSION 3.16)
project(Meme_maker)

set(CMAKE_CXX_STANDARD 17)

add_executable(Meme_maker main.cpp bmp.h bmp.cpp resizer.h resizer.cpp meme_maker.cpp meme_maker.h letters_array.h)