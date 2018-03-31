cmake_minimum_required(VERSION 3.5)
project(adder C)

add_library(adder src/add.c)

target_include_directories(adder PUBLIC  include)
target_include_directories(adder PRIVATE src)

add_executable(adder_test tests/add_test.c)
target_link_libraries(adder_test adder)
add_test(adder_test adder_test)
