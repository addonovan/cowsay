cmake_minimum_required(VERSION 3.5)
project(cowsay)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp cowsayer.cpp cowsayer.h)
add_executable(cowsay ${SOURCE_FILES})