
# Function to add ctest executed compilation test that
# is intended to fail.  This is used to test that the api
# is properly excluding cases designed to create a
# compilation failure
function(add_compile_fail_test name source depend)

# Add a couple of failing-to-compile targets
add_executable(${name} ${source})
# Avoid building these targets normally
set_target_properties(${name} PROPERTIES
                       EXCLUDE_FROM_ALL TRUE
                       EXCLUDE_FROM_DEFAULT_BUILD TRUE)

target_link_libraries(${name} PRIVATE ${depend})

add_test(NAME ${name}-test
         COMMAND ${CMAKE_COMMAND} --build . --target ${name} --config $<CONFIGURATION>
         WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

set_tests_properties(${name}-test PROPERTIES	WILL_FAIL TRUE)


message("adding compile-fail test: ${name}-test using ${source}")
endfunction()
