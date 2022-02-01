cmake_minimum_required(VERSION 3.17)
project(prog_08)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra" )

add_executable(prog_08 main.cpp Graph.h)