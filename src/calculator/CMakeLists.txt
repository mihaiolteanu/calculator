cmake_minimum_required(VERSION 3.5)
project(calculator C)

add_executable(calculator src/calculator.c)
target_link_libraries(calculator maths)
