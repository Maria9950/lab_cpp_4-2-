# Минимальная требуемая версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(CPP_1)

# Добавьте источник в исполняемый файл этого проекта
add_executable(CPP_1 "CPP_1.cpp" "CPP_1.h" "test.cpp")

# Устанавливаем стандарт C++ (если требуется)
if (CMAKE_VERSION VERSION_GREATER 3.12)
    set_property(TARGET CPP_1 PROPERTY CXX_STANDARD 20)
endif()

# Копируем файл inp.txt в директорию сборки
configure_file(${CMAKE_SOURCE_DIR}/inp.txt ${CMAKE_BINARY_DIR}/inp.txt COPYONLY)


# Указываем рабочую директорию
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

