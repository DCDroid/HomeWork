cmake_minimum_required(VERSION 3.22.0)
project(my_first_cmake_project)

set(CMAKE_C_COMPILER "gcc-11.4.0")

# General headers

file(GLOB_RECURSE RACING_H "General/*.h")

if (NOT RACING_H)
    message(FATAL_ERROR "No .h files found in the current directory!")
endif()
message(RACING_H " files:")
foreach(file ${RACING_H})
    message("${file}")
endforeach()

# General source
file(GLOB_RECURSE RACING_CPP "General/*.cpp")
if (NOT RACING_CPP)
    message(FATAL_ERROR "No .cpp files found in the current directory!")
endif()
message(RACING_CPP " files:")
foreach(file ${RACING_CPP})
    message("${file}")
endforeach()

# Library
add_library(RacingLib SHARED ${RASING_H} ${RACING_CPP})

# Executable file
add_executable(out.o main.cpp)

target_link_libraries(out.o RacingLib)