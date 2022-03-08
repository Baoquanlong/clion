cmake_minimum_required(VERSION 3.21)
project(BTree)

set(CMAKE_CXX_STANDARD 14)

add_executable(BTree main.cpp header.h BTree.cpp)
