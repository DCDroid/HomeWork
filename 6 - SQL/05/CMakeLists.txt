cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(out.o)

set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_COMPILER "/usr/bin/g++-11")


add_executable(${PROJECT_NAME} main.cpp 
    Users/src/Users.cpp
    Users/include/Users.h
)

target_link_libraries(out.o PRIVATE pqxx pq)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Users/include)
