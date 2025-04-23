cmake_minimum_required(VERSION 3.10)
project(lab05)

set(CMAKE_CXX_STANDARD 14)

# googletest теперь клонирован локально (альтернативный вариант, если FetchContent не работает)
# include_directories(third-party/googletest/googletest/include)
# link_directories(third-party/googletest/googletest)
# add_library(gtest STATIC third-party/googletest/googletest/src/gtest-all.cc)
# add_library(gtest_main STATIC third-party/googletest/googletest/src/gtest_main.cc)

# Включаем Google Test (если локальное клонирование не используется)
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest
    GIT_BRANCH   main # Используем ветку main
)
FetchContent_MakeAvailable(googletest)

# Создаем библиотеку MyProject (если она нужна)
add_library(MyProject tests/print.cpp)  #  Или другие файлы .cpp, если они есть
target_include_directories(MyProject PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) #  Важно!

# Создаем исполняемый файл для тестов
add_executable(check tests/test1.cpp tests/print.cpp)  # Добавил tests/print.cpp

# Связываем тесты с библиотекой MyProject и gtest
target_link_libraries(check MyProject gtest gtest_main)

# Указываем, где искать заголовочные файлы для MyProject
target_include_directories(check PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}) # Важно!

# Добавляем тесты CTest
include(GoogleTest)
gtest_discover_tests(check)
