cmake_minimum_required(VERSION 3.10)
project(ExampleProject)
set(CMAKE_CXX_STANDARD 14)

include_directories(src)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_subdirectory(src)
add_subdirectory(tst)
#add_subdirectory(lib/googletest)
