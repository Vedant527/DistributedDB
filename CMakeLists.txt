cmake_minimum_required(VERSION 3.15)
project(DistributedDB LANGUAGES CXX)

enable_testing()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include) 
find_package(GTest CONFIG REQUIRED)

# Share library for tests + source
add_library(DistributedDB_Lib STATIC
    src/storage/BinaryTree.cpp
)
target_include_directories(DistributedDB_Lib PUBLIC include)

# Source executable for starting db
add_executable(DistributedDB
    src/main.cpp
)
target_link_libraries(DistributedDB PRIVATE DistributedDB_Lib)

# Test executable
add_executable(DistributedDBTests
    tst/storage/impl/BinaryTreeTests.cpp
)
target_include_directories(DistributedDBTests PRIVATE tst)
target_link_libraries(DistributedDBTests PRIVATE GTest::gtest_main DistributedDB_Lib)
