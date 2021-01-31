# 变量名和其他CMakeLists.txt要不一样
aux_source_directory(. DIR_MATH_SRC)

# 生成静态库
add_library(MathFunctions ${DIR_MATH_SRC})
