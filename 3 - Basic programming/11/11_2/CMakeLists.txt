cmake_minimum_required(VERSION 3.22.0)
project(my_first_cmake_project)

# LEAVER headers
file(GLOB LEAVER_H "Leaver/**.h")
if (NOT LEAVER_H)
    message(FATAL_ERROR "No .h files found in the current directory!")
endif()
message(LEAVER_H " files: ${LEAVER_H}")

# LEAVER source
file(GLOB LEAVER_CPP "Leaver/**.cpp")
if (NOT LEAVER_CPP)
    message(FATAL_ERROR "No .cpp files found in the current directory!")
endif()
message(LEAVER_CPP " files: ${LEAVER_CPP}")

# Library
add_library(LeaverDynamicLib SHARED ${LEAVER_H} ${LEAVER_CPP})

# Executable file
add_executable(out.o main.cpp)

target_link_libraries(out.o LeaverDynamicLib)