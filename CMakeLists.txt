cmake_minimum_required(VERSION 3.16)
project(LinkedList)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinkedList main.cpp Stock.cpp Stock.h Node.h Node.cpp)