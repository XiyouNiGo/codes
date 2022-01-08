cmake_minimum_required(VERSION 3.5)

project(sort)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

add_executable(sort_test sort_test.cc)

include_directories(${PROJECT_SOURCE_DIR})

aux_source_directory(${PROJECT_SOURCE_DIR}/sort SORT_SOURCES)
target_sources(sort_test PRIVATE ${SORT_SOURCES})

target_link_libraries(sort_test PRIVATE gtest gtest_main pthread)

add_test(NAME sort_test COMMAND sort_test)
