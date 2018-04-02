cmake_minimum_required(VERSION 3.5)
project(vendor C)

add_library(unity Unity/src/unity.c)
target_include_directories(unity PUBLIC Unity/src/)

add_library(cmock cmock/src/cmock.c Unity)
target_link_libraries(cmock unity)
target_include_directories(cmock PUBLIC cmock/src)


