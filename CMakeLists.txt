cmake_minimum_required(VERSION 3.21)
project(Project2)

set(CMAKE_CXX_STANDARD 14)

add_executable(Project2 main.cpp Node.cpp Node.h SkipList.cpp SkipList.h)
