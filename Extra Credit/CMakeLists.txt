cmake_minimum_required(VERSION 3.12)
project(data_structures_assignment_extra)

set(CMAKE_CXX_STANDARD 17)

add_executable(problem1 problem1/bag.h problem1/bag.cpp problem1/exam.cpp)
add_executable(problem2 problem2/node.h problem2/node.cpp problem2/exam.cpp)
add_executable(problem3 problem3/hashfunctions.h problem3/hashfunctions.cpp problem3/hashfunctiontest.h problem3/exam.cpp)
add_executable(problem4 problem4/bintree.h problem4/exam.cpp)
