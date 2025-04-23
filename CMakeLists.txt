cmake_minimum_required(VERSION 3.10)
project(lab05)

set(CMAKE_CXX_STANDARD 14)

# Создаем библиотеку MyProject
add_library(MyProject tests/print.cpp)
target_include_directories(MyProject PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Создаем исполняемый файл для тестов
add_executable(check tests/test1.cpp) #Указываем, что print.cpp входит в check

# Указываем, где искать заголовочные файлы для check (важно!)
target_include_directories(check PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Связываем тесты с библиотекой MyProject и gtest
target_link_libraries(check MyProject gtest gtest_main)

# Добавляем тесты CTest
include(GoogleTest)
gtest_discover_tests(check)
