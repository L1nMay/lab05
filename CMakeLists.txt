cmake_minimum_required(VERSION 3.10)
project(lab05)

set(CMAKE_CXX_STANDARD 14)

# Пути
set(PROJECT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(GTEST_INCLUDE_DIR /usr/include/gtest) #  Правильный путь!

# Создаем библиотеку MyProject
add_library(MyProject ${PROJECT_SOURCE_DIR}/tests/print.cpp)
target_include_directories(MyProject PUBLIC ${PROJECT_SOURCE_DIR})  # Путь к заголовочным файлам

# Создаем исполняемый файл для тестов
add_executable(check ${PROJECT_SOURCE_DIR}/tests/test1.cpp)

# Указываем пути и флаги для check
target_include_directories(check PUBLIC
    ${PROJECT_SOURCE_DIR}
    ${GTEST_INCLUDE_DIR}
)

target_link_libraries(check
    MyProject
    gtest
    gtest_main
)

# Флаги компиляции (на всякий случай)
target_compile_options(check PUBLIC
    "-Wall"
    "-Wextra"
    "-pthread"  # Если gtest требует pthread
)

# Добавляем тесты CTest
include(GoogleTest)
gtest_discover_tests(check)
