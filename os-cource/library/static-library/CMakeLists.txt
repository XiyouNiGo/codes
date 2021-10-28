cmake_minimum_required(VERSION 3.5)

project(philosopher)

# Generate libphilosopher.a
add_library(philosopher STATIC philosopher/philosopher.c)

target_include_directories(philosopher PUBLIC ${PROJECT_SOURCE_DIR}/philosopher)

target_link_libraries(philosopher pthread)

add_executable(hello_philosopher main.c)

target_link_libraries(hello_philosopher PRIVATE philosopher)