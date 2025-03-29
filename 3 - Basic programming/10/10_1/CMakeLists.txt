cmake_minimum_required(VERSION 3.22.0)
project(my_first_cmake_project)

# Собираем все .cpp файлы в текущей директории
file(GLOB SRC_SRC "*.cpp")

# Проверяем, есть ли файлы
if (NOT SRC_SRC)
    message(FATAL_ERROR "No .cpp files found in the current directory!")
endif()

# Выводим список найденных файлов (для отладки)
message(STATUS "Source files: ${SRC_SRC}")

# Создаем исполняемый файл
add_executable(my_first_cmake_program ${SRC_SRC})