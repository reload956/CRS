cmake_minimum_required(VERSION 3.12)
project(calculator)

set(CMAKE_CXX_STANDARD 14)

add_executable(calculator main.cpp src/solver.cpp src/solver.h)