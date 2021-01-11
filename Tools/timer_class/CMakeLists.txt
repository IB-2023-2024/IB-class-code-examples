# Universidad de La Laguna
# Escuela Superior de Ingeniería y Tecnología
# Grado en Ingeniería Informática
# Informática Básica
#
# @author F. de Sande
# @date 11 Jan 2020
# @brief CMakeLists.txt for the Timer class
#
# Build process:
#   1. cd <project_folder>
#   2. mkdir build
#   3. cd build
#   4. cmake ..
#   5. make


cmake_minimum_required(VERSION 3.1)  # Mandatory

# set the project name 
project(GTests                # Mandatory
    VERSION 1.0
    DESCRIPTION "A simple CMake project for the Fibonacci Sum application"
    LANGUAGES CXX)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14) 						# Use c++14
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# Debug and release flags
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

# Adds an executable target called "runTests" to be built from the source files listed in the command invocation.
add_executable(runTests
    test/gtest_main.cc
    src/utils.h
    src/utils.cc
    src/timer.h
    src/timer.cc
    test/test_timer.cc)

add_executable(timer_program
    src/utils.h
    src/utils.cc
    src/timer.h
    src/timer.cc
		src/timer_program.cc)

target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

# Add expected compiler features to a target.
target_compile_features(runTests PRIVATE cxx_std_14)

# Add compile options to a target.
target_compile_options(runTests PRIVATE -Wall -Wextra -Wpedantic)
