cmake_minimum_required(VERSION 3.13)
project(AdventOfCode)

set(CMAKE_CXX_STANDARD 17)

set(SOURCES include/Day1.h src/Day1.cpp include/Day2.h src/Day2.cpp include/Computer.h src/Computer.cpp)

add_executable(AdventOfCode main.cpp ${SOURCES})
target_include_directories(AdventOfCode PRIVATE include)
