cmake_minimum_required(VERSION 3.12)
project(Assignment2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(main
        sequence1.cpp sequence1.h main.cpp)
add_executable(exam
        sequence1.cpp sequence1.h sequence_exam.cpp)
add_executable(test
        sequence1.cpp sequence1.h sequence_test.cpp)