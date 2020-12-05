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
# 1. cd <project_folder>
# 2. mkdir build
# 3. cd build
# 4. cmake ..
# 5. make


cmake_minimum_required(VERSION 3.1)  # Mandatory

project(fibonacci_sum                # Mandatory
    VERSION 1.0
    DESCRIPTION "A simple CMake project for the Fibonacci Sum application"
    LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14) 						# Use c++14

add_executable(fibonacci_sum
    src/fibonacci_sum.h
    src/fibonacci_sum.cc
    src/tools.h
    src/tools.cc
    src/fibonacci_main.cc)

target_compile_features(fibonacci_sum PRIVATE cxx_std_14)
target_compile_options(fibonacci_sum PRIVATE -Wall -Wextra -Wpedantic)
