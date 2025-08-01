cmake_minimum_required(VERSION 3.22.0)
project(mproject)

set (CMAKE_CXX_STANDARD 17)

include_directories(include)

# Собираем все .cpp файлы в текущей директории
file(GLOB SRC_SRC "src/*.cpp" "main.cpp")

# Проверяем, есть ли файлы
if (NOT SRC_SRC)
    message(FATAL_ERROR "No .cpp files found in the current directory!")
endif()

# Выводим список найденных файлов (для отладки)
message(STATUS "Source files: ${SRC_SRC}")

# Собираем все .h файлы в текущей директории
file(GLOB HEADER_FILES "include/*.h")

# Проверяем, есть ли файлы
if (NOT HEADER_FILES)
    message(FATAL_ERROR "No .h files found in the current directory!")
endif()

# Выводим список найденных файлов (для отладки)
message(STATUS "Header files: ${HEADER_FILES}")

# Создаем исполняемый файл
add_executable(out.o ${SRC_SRC} ${HEADER_FILES})