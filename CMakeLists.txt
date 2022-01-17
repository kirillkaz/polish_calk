cmake_minimum_required(VERSION 3.20)
project(polish_calk)

set(CMAKE_CXX_STANDARD 23)

add_executable(polish_calk main.cpp PolishCalk.cpp PolishCalk.h)

add_subdirectory(tests/googletest)
enable_testing()
#include_directories(${STACK_INCLUDE_DIR})
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
target_link_libraries(polish_calk gtest gtest_main)