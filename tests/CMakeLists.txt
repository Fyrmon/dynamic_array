find_package(GTest)
enable_testing()

add_executable(arr_test ${CMAKE_CURRENT_SOURCE_DIR}/tests.cpp)

target_link_libraries(arr_test 
PRIVATE
   dyn_arr_lib
   GTest::gtest
   GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(arr_test)