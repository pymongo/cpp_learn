cmake_minimum_required(VERSION 3.16)
project(learn_cpp)
set(CMAKE_CXX_STANDARD 17)

# 添加boost库的方法_1(不能跨平台)
#通过`brew install boost`或`sudo apt install libboost-all-dev`安装的boost会自动安装到include_path和link_path中
#include_directories(/usr/include/boost)
#link_directories(/usr/lib/arm-linux-gnueabihf)

# 添加boost库的方法_2
#find_package(Boost)
#if (${Boost_FOUND})
#    include_directories(${Boost_INCLUDE_DIRS})
#    message(STATUS "find_package(Boost) ok")
#else (${Boost_FOUND})
#    message(FATAL_ERROR "find_package(Boost) failed!")
#endif (${Boost_FOUND})

# third-party libraries API
#为了照顾没有安装boost的机器，所有以来boost库的executable请自行打命令链接和编译
#add_executable(boost_example_random third_party_lib/boost_example_random.cpp)
#target_link_libraries(boost_example_random ${Boost_LIBRARIES})
add_executable(sqlite third_party_lib/sqlite.c)
target_link_libraries(sqlite sqlite3)# sqlite3库单Header单so比较简单，可以这么导入

# standard libraries API
add_executable(regex std_lib/regex.c)
add_executable(stdin_c std_lib/stdin.c)
add_executable(stdin_cpp std_lib/stdin.cpp)
add_executable(file_input_stream std_lib/fixme_ifstream.cpp)
add_executable(return_value_of_printf std_lib/return_value_of_printf.c)
add_executable(thread_run_interval_print_time std_lib/thread_run_interval_print_time.cpp)
add_executable(fork_child_process_and_wait std_lib/fork_child_process_and_wait.c)

# leetcode
add_executable(n_ary_tree_level_order leetcode/bfs/n_ary_tree_level_order.cpp)
add_executable(keys_and_rooms leetcode/bfs/keys_and_rooms.cpp)
add_executable(transpose_matrix leetcode/easy/transpose_matrix.cpp)
add_executable(reverse_words_in_a_string_3 leetcode/easy/reverse_words_in_a_string_3.cpp)
add_executable(remove_duplicates_from_sorted_list leetcode/linked_list/remove_duplicates_from_sorted_list.cpp)
add_executable(dining_philosophers_problem leetcode/concurrency/dining_philosophers_problem.cpp)
add_executable(add_bigint_string leetcode/easy/add_bigint_string.cpp)
add_executable(print_immutable_linked_list_in_reverse leetcode/easy/print_immutable_linked_list_in_reverse.c)

# grammar_datatype
add_executable(size_of_integer grammar_datatype/size_of_integer.cpp)
add_executable(wchar grammar_datatype/wchar.cpp)
add_executable(string_offset grammar_datatype/string_offset.c)
add_executable(inline_asm std_lib/inline_asm.c)
add_executable(impl_strcpy grammar_datatype/impl_strcpy.cpp)
add_executable(operator_overload grammar_datatype/operator_overload.cpp)
add_executable(stdarg_valist grammar_datatype/stdarg_valist.c)

# cpp_class
add_executable(polymorphism cpp_class/polymorphism.cpp)
add_executable(dynamic_cast cpp_class/dynamic_cast.cpp)

add_executable(temp temp.cpp)