cmake_minimum_required(VERSION 3.12)
project(data_structures_assignment6)

set(CMAKE_CXX_STANDARD 17)

add_executable(main main.cpp bstbag.h bintree.h)
add_executable(exam bagexam.cpp bstbag.h bintree.h)
add_executable(test bagtest.cpp bstbag.h bintree.h)