cmake_minimum_required(VERSION 3.5)
project(adder C)
include(create_test)

add_library(adder src/add.c)

target_include_directories(adder PUBLIC  include)
target_include_directories(adder PRIVATE src)

create_test(add_test tests/add_test.c adder)
