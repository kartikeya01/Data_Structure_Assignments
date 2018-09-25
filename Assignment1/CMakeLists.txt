cmake_minimum_required(VERSION 3.12)
project(Assignment1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Assignment1
        barrel.cpp
        barrel.h
        main.cpp
        test_barrel.h)
