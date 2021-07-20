cmake_minimum_required(VERSION 3.16)
project(learn_cpp)
set(CMAKE_CXX_STANDARD 17)

#[[
# 添加boost库的方法_1(不能跨平台): 通过`brew install boost`或`apt install libboost-all-dev`安装的boost会安到相应操作系统的include和link path中
include_directories(/usr/include/boost)
link_directories(/usr/lib/arm-linux-gnueabihf)
# 添加boost库的方法_2(需要操作系统已装boost库)
find_package(Boost)
if (${Boost_FOUND})
    include_directories(${Boost_INCLUDE_DIRS})
    message(STATUS "find_package(Boost) ok")
else (${Boost_FOUND})
    message(FATAL_ERROR "find_package(Boost) failed!")
endif (${Boost_FOUND})
# 为了照顾没有安装boost的机器，所有以来boost库的executable请自行打g++编译
add_executable(boost_example_random third_party_lib/boost_example_random.cpp)
target_link_libraries(boost_example_random ${Boost_LIBRARIES})
]]

# temp
add_executable(temp temp.c)
target_link_libraries(temp pthread)

# C++ grammar
#add_executable(sum_parameter_pack_or_va_list cpp_grammar/sum_parameter_pack_or_va_list.cpp)
add_executable(polymorphism cpp_grammar/class/polymorphism.cpp)
add_executable(dynamic_cast cpp_grammar/class/dynamic_cast.cpp)

# third-party libraries API
find_package(PkgConfig REQUIRED)
add_executable(openssl_md5 third_party_lib/openssl_md5.c)
target_link_libraries(openssl_md5 crypto) # gcc -lssl or gcc -lcrypto
add_executable(curl_http_request third_party_lib/curl_http_request.c)
target_link_libraries(curl_http_request curl)

#[[
# standard libraries API
#add_executable(regex std_lib/regex.c)
#add_executable(stdin_c std_lib/stdin.c)
#add_executable(stdin_cpp std_lib/stdin.cpp)
#add_executable(file_input_stream std_lib/fixme_ifstream.cpp)
#add_executable(return_value_of_printf std_lib/return_value_of_printf.c)

# leetcode
#add_executable(n_ary_tree_level_order leetcode/bfs/n_ary_tree_level_order.cpp)
#add_executable(remove_duplicates_from_sorted_list leetcode/linked_list/remove_duplicates_from_sorted_list.cpp)
#add_executable(dining_philosophers_problem leetcode/concurrency/dining_philosophers_problem.cpp)
#add_executable(add_bigint_string leetcode/easy/add_bigint_string.cpp)
#add_executable(print_immutable_linked_list_in_reverse leetcode/easy/print_immutable_linked_list_in_reverse.c)

# grammar_datatype
#add_executable(size_of_integer grammar_datatype/size_of_integer.cpp)
#add_executable(string_offset grammar_datatype/string_offset.c)
#add_executable(inline_asm std_lib/inline_asm.c)
#add_executable(impl_strcpy grammar_datatype/impl_strcpy.cpp)
#add_executable(operator_overload grammar_datatype/operator_overload.cpp)
#add_executable(stdarg_valist grammar_datatype/stdarg_valist.c)
]]
