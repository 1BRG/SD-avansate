cmake_minimum_required(VERSION 3.30)
project(SD)

set(CMAKE_CXX_STANDARD 20)

add_executable(SD main.cpp
            src/rp_heap.cpp
            src/leftist_heap.cpp
            src/heap.cpp
        include/leftist_heap.h
        include/rp_heap.h
        include/heap.h

)
