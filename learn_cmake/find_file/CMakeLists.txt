cmake_minimum_required(VERSION 3.5)

project(find_file_test)

# find_file(TEST_FILES PATHS ${PROJECT_SOURCE_DIR}
#   PATH_SUFFIXES "test.cc"
# )

file(GLOB_RECURSE TEST_FILES "*test.cc")
list(LENGTH TEST_FILES TEST_FILES_LENGTH)

message(${TEST_FILES})
message(${TEST_FILES_LENGTH})

foreach(test_file ${TEST_FILES})
message(${test_file})  
endforeach()