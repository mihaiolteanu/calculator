cmake_minimum_required(VERSION 3.5)
project(divider C)
include(create_test)

add_library(divider src/divide.c)
target_include_directories(divider PUBLIC  include)
target_include_directories(divider PRIVATE src)

get_filename_component(header_abs_path include/divide.h REALPATH )
create_mock(mock_divide ${header_abs_path})
