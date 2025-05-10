cmake_minimum_required(VERSION 3.30)
project(SD)

set(CMAKE_CXX_STANDARD 20)

if(NOT Python3_EXECUTABLE)
    find_package(Python3 REQUIRED COMPONENTS Interpreter)
else()
    set(Python3_EXECUTABLE ${Python3_EXECUTABLE} CACHE FILEPATH "" FORCE)
endif()

add_executable(SD main.cpp
            src/rp_heap.cpp
            src/leftist_heap.cpp
            src/heap.cpp
        include/leftist_heap.h
        include/rp_heap.h
        include/heap.h
)
add_custom_target(gen_tests
        COMMAND ${Python3_EXECUTABLE} ${CMAKE_SOURCE_DIR}/generator/generator.py
        --out-dir ${CMAKE_SOURCE_DIR}/tests
        --sets 100 500 500
        --ops 1000000 4000000 10000000
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Generare teste pentru heap-uri"
        VERBATIM
)