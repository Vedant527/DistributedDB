cmake_minimum_required(VERSION 3.15)
project(DistributedDB LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
add_executable(DistributedDB
    src/main.cpp
    src/storage/BinaryTree.cpp
)

