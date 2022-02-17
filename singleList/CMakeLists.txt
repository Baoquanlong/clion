cmake_minimum_required(VERSION 3.20)
project(singleList)

set(CMAKE_CXX_STANDARD 11)

add_executable(main main.cpp LinkNode.cpp sqlist.cpp unionSet.cpp LinkNode.h sqlist.h unionSet.h)
