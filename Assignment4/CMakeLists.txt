cmake_minimum_required(VERSION 3.12)
project(Assignment4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(main
        sequence3.cpp sequence3.h node1.cpp node1.h main.cpp)
add_executable(exam
        sequence3.cpp sequence3.h node1.cpp node1.h sequence3_exam.cpp)
add_executable(test
        sequence3.cpp sequence3.h node1.cpp node1.h sequence3_test.cpp)