cmake_minimum_required(VERSION 3.12)
project(Assignment3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(main
        sequence2.cpp sequence2.h main.cpp)
add_executable(exam
        sequence2.cpp sequence2.h sequence2_exam.cpp)
add_executable(test
        sequence2.cpp sequence2.h sequence2_test.cpp)