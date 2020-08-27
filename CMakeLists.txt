cmake_minimum_required(VERSION 3.16)
project(cpp_learn)
# set(CMAKE_CXX_STANDARD 11)
# https://stackoverflow.com/questions/27788385/mixing-c-and-c-sources-in-cmake
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

# https://stackoverflow.com/questions/13440744/cmake-how-to-compile-based-on-different-main-entries
# this would involve compiling the sources twice and is inefficient
# 不然就只能挨地敲g++地编译了
add_executable(size_of_integer size_of_integer.cpp)
add_executable(return_value_of_printf return_value_of_printf.c)
add_executable(thread_run_interval_print_time thread_run_interval_print_time.cpp)
add_executable(leetcode_bfs_maximum_depth_of_n_arr_tree leetcode/bfs/maximum_depth_of_n_ary_tree.cpp)
add_library(
        my_lib
        size_of_integer.cpp
        return_value_of_printf.c
        thread_run_interval_print_time.cpp
        leetcode/bfs/maximum_depth_of_n_ary_tree.cpp)

target_link_libraries(size_of_integer my_lib)
target_link_libraries(return_value_of_printf my_lib)
target_link_libraries(thread_run_interval_print_time my_lib)
target_link_libraries(leetcode_bfs_maximum_depth_of_n_arr_tree my_lib)
