cmake_minimum_required(VERSION 3.5)
project(calculator C)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake_common)

enable_testing()
add_subdirectory(src)
add_subdirectory(vendor)


