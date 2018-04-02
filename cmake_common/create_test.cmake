function(create_test test_name test_src test_dep)
  get_filename_component( test_src_absolute ${test_src} REALPATH )
  add_custom_command    (OUTPUT ${test_name}_runner.c
    COMMAND
    ruby ${CMAKE_SOURCE_DIR}/vendor/Unity/auto/generate_test_runner.rb
    ${CMAKE_SOURCE_DIR}/cmake_common/project.yml
    ${test_src_absolute} ${test_name}_runner.c
    DEPENDS ${test_src})
  add_executable        (${test_name} ${test_src} ${test_name}_runner.c)
  target_link_libraries (${test_name} unity)
  target_link_libraries (${test_name} ${test_dep})
  add_test              (${test_name} ${test_name})
endfunction()

# Generates a mock library based on a module's header file
function(create_mock mock_name header_abs_path)
  get_filename_component(header_folder ${header_abs_path} DIRECTORY)
  file(MAKE_DIRECTORY ${header_folder}/mocks)
  add_custom_command (
    OUTPUT ${header_folder}/mocks/${mock_name}.c
    COMMAND ruby
            ${CMAKE_SOURCE_DIR}/vendor/cmock/lib/cmock.rb
            -o${CMAKE_SOURCE_DIR}/cmake_common/project.yml
            ${header_abs_path}
    WORKING_DIRECTORY ${header_folder}
    DEPENDS ${header_abs_path})
  
  add_library(${mock_name} ${header_folder}/mocks/${mock_name}.c)
  target_include_directories(${mock_name} PUBLIC  ${header_folder})
  target_include_directories(${mock_name} PUBLIC  ${header_folder}/mocks)
  target_link_libraries(${mock_name} unity)
  target_link_libraries(${mock_name} cmock)
endfunction()
