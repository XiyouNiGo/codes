cmake_minimum_required(VERSION 2.8)

project(Demo3)

aux_source_directory(. DIR_SRC)

# 子目录下的CMakeLists.txt也会被处理
add_subdirectory(math)

add_executable(Demo main.c)

# 添加链接库
target_link_libraries(Demo MathFunctions)
