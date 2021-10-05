cmake_minimum_required(VERSION 3.16)
project(advanced_software_engineering)

set(CMAKE_CXX_STANDARD 14)

set (Boost_USE_STATIC_LIBS OFF)
find_package (Boost REQUIRED COMPONENTS unit_test_framework)
include_directories (${Boost_INCLUDE_DIRS})

include_directories(src/main/bst
        src/main/bst/src)

add_executable(BinarySearchTreeTests
        src/main/bst/src/BST.cpp
        src/main/bst/src/BST.h
        src/test/bst/BinarySearchTreeTests.cpp src/main/hashtable/src/HashTable.cpp src/main/hashtable/src/HashTable.h)

add_executable(ManualTesting
        src/main/bst/src/BST.cpp
        src/main/bst/src/BST.h
        src/main/bst/src/main.cpp)

add_executable(HashTable
        src/main/hashtable/src/HashTable.cpp
        src/main/hashtable/src/HashTable.h
        src/main/hashtable/src/main.cpp)

target_link_libraries (BinarySearchTreeTests ${Boost_LIBRARIES})