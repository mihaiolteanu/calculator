cmake_minimum_required(VERSION 3.5)
project(targets C)

add_subdirectory(substractor)
add_subdirectory(adder)
add_subdirectory(multiplier)
add_subdirectory(divider)

add_library(maths INTERFACE)
target_link_libraries(maths INTERFACE adder multiplier divider substractor)
