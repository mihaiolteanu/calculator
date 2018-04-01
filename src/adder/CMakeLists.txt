cmake_minimum_required(VERSION 3.5)
project(adder C)
include(create_test)

add_library(adder src/add.c)
target_include_directories(adder PUBLIC  include)
target_include_directories(adder PRIVATE src)

create_test(add_test tests/add_test.c adder)

get_filename_component(header_abs_path include/add.h REALPATH )
create_mock(mock_add ${header_abs_path})
