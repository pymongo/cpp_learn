cmake_minimum_required(VERSION 3.16)
project(learn_cpp)
set(CMAKE_CXX_STANDARD 17)

# 添加boost库的方法_1(不能跨平台)
#通过`brew install boost`或`sudo apt install libboost-all-dev`安装的boost会自动安装到include_path和link_path中
#include_directories(/usr/include/boost)
#link_directories(/usr/lib/arm-linux-gnueabihf)

# 添加boost库的方法_2
find_package(Boost)
if (${Boost_FOUND})
    include_directories(${Boost_INCLUDE_DIRS})
    message(STATUS "find_package(Boost) ok")
else (${Boost_FOUND})
    message(FATAL_ERROR "find_package(Boost) failed!")
endif (${Boost_FOUND})

# third-party libraries API
add_executable(boost_example_random third_party_lib/boost_example_random.cpp)
#target_link_libraries(boost_example_random boost_random) # Boost这个库头文件很多，不能引入
target_link_libraries(boost_example_random ${Boost_LIBRARIES})
add_executable(sqlite third_party_lib/sqlite.c)
target_link_libraries(sqlite sqlite3)# sqlite3库单Header单so比较简单，可以这么导入
# standard libraries API
add_executable(regex std_lib/regex.c)

add_executable(stdin_c stdin.c)
add_executable(stdin_cpp stdin.cpp)
add_executable(file_input_stream file_input_stream.cpp)
add_executable(return_value_of_printf return_value_of_printf.c)
add_executable(thread_run_interval_print_time thread_run_interval_print_time.cpp)
add_executable(impl_strcpy impl_strcpy.cpp)
add_executable(polymorphism polymorphism.cpp)
add_executable(operator_overload operator_overload.cpp)
# leetcode
add_executable(n_ary_tree_level_order leetcode/bfs/n_ary_tree_level_order.cpp)
add_executable(keys_and_rooms leetcode/bfs/keys_and_rooms.cpp)
add_executable(combinations leetcode/backtracking/combinations.cpp)
add_executable(transpose_matrix leetcode/easy/transpose_matrix.cpp)
add_executable(reverse_words_in_a_string_3 leetcode/easy/reverse_words_in_a_string_3.cpp)
add_executable(remove_duplicates_from_sorted_list leetcode/linked_list/remove_duplicates_from_sorted_list.cpp)
add_executable(dining_philosophers_problem leetcode/concurrency/dining_philosophers_problem.cpp)
add_executable(add_bigint_string leetcode/easy/add_bigint_string.cpp)
# system_call
add_executable(fork_child_process_and_wait system_call/fork_child_process_and_wait)
# datatype
add_executable(size_of_integer datatype/size_of_integer.cpp)
add_executable(wchar datatype/wchar.cpp)
add_executable(string_offset datatype/string_offset.c)
add_executable(inline_asm inline_asm.c)
