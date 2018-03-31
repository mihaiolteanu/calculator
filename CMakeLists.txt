cmake_minimum_required(VERSION 3.5)
project(calculator C)

add_subdirectory(targets)

add_executable(calculator calculator.c)
target_link_libraries(calculator maths)


