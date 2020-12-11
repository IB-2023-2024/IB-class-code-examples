# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author F. de Sande
# @date 18 Jun 2020
# @brief CMakeLists.txt example
# CMakeLists.txt defines the whole build
# CMake reads CMakeLists.txt sequentially
#
# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make


cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(fibonacci_sum                # Mandatory
    VERSION 1.0
    DESCRIPTION "A simple CMake project for the Fibonacci Sum application"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14) 						# Use c++14
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Adds an executable target called "fibonacci_sum" to be built from the source files listed in the command invocation.
add_executable(fibonacci_sum
    src/fibonacci_sum.h
    src/fibonacci_sum.cc
    src/tools.h
    src/tools.cc
    src/fibonacci_main.cc)

# Add expected compiler features to a target.
target_compile_features(fibonacci_sum PRIVATE cxx_std_14)

# Add compile options to a target.
target_compile_options(fibonacci_sum PRIVATE -Wall -Wextra -Wpedantic)
