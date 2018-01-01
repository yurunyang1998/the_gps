cmake_minimum_required(VERSION 3.8)
project(the_gps)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp the_classes_declaration.h the_realize_of_classes.cpp)
add_executable(the_gps ${SOURCE_FILES})