cmake_minimum_required(VERSION 3.5)

project (hello_ld_preload)

set(CMAKE_CXX_STANDARD 11)

option(USE_LD_PRELOAD "Use self-defined say_hello function by LD_PRELOAD" OFF)

# Generate libhello.so.
add_library(hello SHARED src/say_hello.cpp)

target_include_directories(hello PUBLIC ${PROJECT_SOURCE_DIR}/include)

if (USE_LD_PRELOAD)
  add_library(my_hello SHARED src/my_say_hello.cpp)
  target_include_directories(my_hello PUBLIC ${PROJECT_SOURCE_DIR}/include)
  # No use outside, please set env yourself.
  set(ENV{LD_PRELOAD} "my_hello")
endif (USE_LD_PRELOAD)

add_executable(hello_ld_preload src/main.cpp)

target_link_libraries(hello_ld_preload PRIVATE hello)