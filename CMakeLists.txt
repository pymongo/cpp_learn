cmake_minimum_required(VERSION 3.16)
project(cpp_learn)
# set(CMAKE_CXX_STANDARD 11)
# https://stackoverflow.com/questions/27788385/mixing-c-and-c-sources-in-cmake
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

# https://stackoverflow.com/questions/13440744/cmake-how-to-compile-based-on-different-main-entries
# this would involve compiling the sources twice and is inefficient
# 不然就只能挨地敲g++地编译了
add_executable(size_of_integer size_of_integer.cpp)
add_executable(MyExe2 main2.cpp)
add_executable(TEST return_value_of_printf.c)
add_library(my_lib size_of_integer.cpp main2.cpp return_value_of_printf.c)

target_link_libraries(size_of_integer my_lib)
target_link_libraries(MyExe2 my_lib)
target_link_libraries(TEST my_lib)
