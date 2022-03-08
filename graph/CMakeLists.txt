cmake_minimum_required(VERSION 3.21)
project(graph)

set(CMAKE_CXX_STANDARD 14)

add_executable(graph main.cpp graph.h graphOperation.cpp)
