cmake_minimum_required(VERSION 3.30)
project(SD)

set(CMAKE_CXX_STANDARD 20)

add_executable(SD main.cpp
            include/rp_heap.h
            src/rp_heap.cpp

)
