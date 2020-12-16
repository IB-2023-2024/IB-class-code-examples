cmake_minimum_required(VERSION 3.10)
project(ExampleProject)
set(CMAKE_CXX_STANDARD 14)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests unittest_SimpleMath.cc)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)
