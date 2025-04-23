cmake_minimum_required(VERSION 3.10)
project(lab05)

set(CMAKE_CXX_STANDARD 14)

# Пути
set(GTEST_INCLUDE_DIR /usr/include/gtest)

# Создаем исполняемый файл для тестов
add_executable(test_executable
    tests/test1.cpp
    test_main.cpp
    tests/print.cpp
)

# Указываем пути и библиотеки для test_executable
target_include_directories(test_executable PUBLIC
    ${GTEST_INCLUDE_DIR}
)

target_link_libraries(test_executable
    gtest
    gtest_main
)

# Явно указываем, что test_executable является тестом CTest
add_test(NAME MyTests COMMAND test_executable)

# Закомментируйте эту строку
#include(GoogleTest)

# Правила установки
set(CMAKE_INSTALL_PREFIX "${CMAKE_SOURCE_DIR}/_install" CACHE PATH "Install path prefix" FORCE) #Установим префикс
install(TARGETS test_executable DESTINATION bin)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/tests DESTINATION share/lab05) #Установим папку tests
