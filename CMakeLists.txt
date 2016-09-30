cmake_minimum_required(VERSION 2.8.7)
project(BinarySearchTree)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES tests/catch.hpp tests/size.cpp tests/find.cpp tests/insert.cpp tests/main.cpp)

set(TESTS_SOURCE examples/main.cpp source/BinarySearchTree.cpp)

add_executable(BinarySearchTree ${SOURCE_FILES})
add_executable(Tests ${TESTS_SOURCE})
