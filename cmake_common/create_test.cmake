function(create_test test_name test_src test_dep)
  get_filename_component( test_src_absolute ${test_src} REALPATH )
  add_custom_command    (OUTPUT ${test_name}_runner.c
    COMMAND
    ruby ${CMAKE_SOURCE_DIR}/vendor/Unity/auto/generate_test_runner.rb
    ${test_src_absolute} ${test_name}_runner.c
    DEPENDS ${test_src})
  add_executable        (${test_name} ${test_src} ${test_name}_runner.c)
  target_link_libraries (${test_name} unity)
  target_link_libraries (${test_name} ${test_dep})
  add_test              (${test_name} ${test_name})
endfunction()
