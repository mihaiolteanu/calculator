cmake_minimum_required(VERSION 3.5)
project(multiplier C)

add_library(multiplier src/multiply.c)

target_include_directories(multiplier PUBLIC  include)
target_include_directories(multiplier PRIVATE src)
