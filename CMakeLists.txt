cmake_minimum_required(VERSION 3.3)
project(Easy_strings)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    main.cpp)

add_executable(Easy_strings ${SOURCE_FILES})