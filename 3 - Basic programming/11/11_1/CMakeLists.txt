cmake_minimum_required(VERSION 3.22.0)
project(my_first_cmake_project)

# Greeter headers
file(GLOB GREETER_H "Greeter/**.h")
if (NOT GREETER_H)
    message(FATAL_ERROR "No .h files found in the current directory!")
endif()
message(GREETER_H " files: ${GREETER_H}")

# Greeter source
file(GLOB GREETER_CPP "Greeter/**.cpp")
if (NOT GREETER_CPP)
    message(FATAL_ERROR "No .cpp files found in the current directory!")
endif()
message(GREETER_CPP " files: ${GREETER_CPP}")

# Library
add_library(GreeterStaticLib STATIC ${GREETER_H} ${GREETER_CPP})

# Executable file
add_executable(out.o main.cpp)

target_link_libraries(out.o GreeterStaticLib)