cmake_minimum_required(VERSION 3.10)
project(MyProject)
set(PROJECT_NAME MyProject)

add_library(${PROJECT_NAME} tests/print.cpp)   # Создаем статическую библиотеку MyProject
include_directories(${CMAKE_SOURCE_DIR}/tests) #  Чтобы тесты могли найти хидер

if(BUILD_TESTS)
enable_testing()
add_subdirectory(third-party/gtest _build/third-party/gtest)
file(GLOB ${PROJECT_NAME}_TEST_SOURCES tests/*.cpp)
add_executable(check ${${PROJECT_NAME}_TEST_SOURCES} tests/print.cpp)
target_link_libraries(check ${PROJECT_NAME} gtest_main)
add_test(NAME check COMMAND check)
target_compile_options(gtest PRIVATE -Wno-maybe-uninitialized)
include_directories(${CMAKE_SOURCE_DIR}/tests)
endif()
