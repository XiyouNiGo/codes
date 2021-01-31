cmake_minimum_required(VERSION 2.8)

project(Demo2)

# 查找指定目录下所有文件
# 并将结果存进指定变量名
aux_source_directory(. DIR_SRC)

add_executable(Demo ${DIR_SRC})
