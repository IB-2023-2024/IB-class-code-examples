cmake_minimum_required(VERSION 2.4)

project(Fibonacci_sum)

include_directories(${PROJECT_SOURCE_DIR})
add_executable(fibonacci_sum fibonacci_main.cc fibonacci_sum.cc)  # be sure there's exactly one main() function in the source files
