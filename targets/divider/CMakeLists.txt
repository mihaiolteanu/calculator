cmake_minimum_required(VERSION 3.5)
project(divider C)

add_library(divider src/divide.c)

target_include_directories(divider PUBLIC  include)
target_include_directories(divider PRIVATE src)
