cmake_minimum_required(VERSION 3.5)

project(integrated_by_cmake)

enable_testing()

add_executable(gtest_test gtest_test.cc)
target_link_libraries(gtest_test gtest gtest_main pthread)

add_test(NAME gtest_test COMMAND gtest_test)
