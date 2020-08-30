cmake_minimum_required(VERSION 3.16)
project(cpp_learn)
# gcc不能编译C++源文件，但是g++可以编译C语言的文件
set(CMAKE_CXX_STANDARD 14)
# https://stackoverflow.com/questions/27788385/mixing-c-and-c-sources-in-cmake
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
#SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

# https://stackoverflow.com/questions/13440744/cmake-how-to-compile-based-on-different-main-entries
# this would involve compiling the sources twice and is inefficient
# 不然就只能挨地敲g++地编译了
add_executable(size_of_integer size_of_integer.cpp)
add_executable(return_value_of_printf return_value_of_printf.c)
add_executable(thread_run_interval_print_time thread_run_interval_print_time.cpp)
add_executable(n_ary_tree_level_order leetcode/bfs/n_ary_tree_level_order.cpp)
add_executable(combinations leetcode/backtracking/combinations.cpp)
add_executable(transpose_matrix leetcode/easy/transpose_matrix.cpp)
add_executable(reverse_words_in_a_string_3 leetcode/easy/reverse_words_in_a_string_3.cpp)
add_executable(remove_duplicates_from_sorted_list leetcode/linked_list/remove_duplicates_from_sorted_list.cpp)
add_library(
        my_lib
        size_of_integer.cpp
        return_value_of_printf.c
        thread_run_interval_print_time.cpp
        leetcode/bfs/n_ary_tree_level_order.cpp
        leetcode/backtracking/combinations.cpp
        leetcode/easy/transpose_matrix.cpp
        leetcode/easy/reverse_words_in_a_string_3.cpp
        leetcode/linked_list/remove_duplicates_from_sorted_list.cpp
#        leetcode/linked_list/linked_list.hpp
)

target_link_libraries(size_of_integer my_lib)
target_link_libraries(return_value_of_printf my_lib)
target_link_libraries(thread_run_interval_print_time my_lib)
target_link_libraries(n_ary_tree_level_order my_lib)
target_link_libraries(combinations my_lib)
target_link_libraries(transpose_matrix my_lib)
target_link_libraries(reverse_words_in_a_string_3 my_lib)
target_link_libraries(remove_duplicates_from_sorted_list my_lib)
