cmake_minimum_required(VERSION 3.5)

project(integrated_by_cmake)

enable_testing()

add_executable(testfixture_test testfixture_test.cc)
target_link_libraries(testfixture_test gtest gtest_main pthread)

add_test(NAME testfixture_test COMMAND testfixture_test)
