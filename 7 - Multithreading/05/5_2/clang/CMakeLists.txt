cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(out.o)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_COMPILER "clang++")

add_executable(${PROJECT_NAME} main.cpp )
