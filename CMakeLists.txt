cmake_minimum_required(VERSION 3.19)
project(bootcamplabs)

set(CMAKE_CXX_STANDARD 14)

add_executable(lab1 lab1.cpp)
add_executable(lab2 lab2.cpp)
add_executable(lab3 lab3.cpp)
add_executable(lab4 lab4.cpp)
add_executable(lab5 lab5.cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Ofast")