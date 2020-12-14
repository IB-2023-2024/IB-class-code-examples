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

project(first_project) 							# Mandatory 
cmake_minimum_required(VERSION 3.1) 	# Mandatory 
set(CMAKE_CXX_STANDARD 14) 						# Use c++14

# tell cmake to output binaries here:
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)

# tell cmake where to look for *.h files
include_directories(${PROJECT_SOURCE_DIR}/src)

# create library " libtools "
add_library(tools src/tools.cc)

# add executable main
add_executable(main src/tools_main.cc)

# tell the linker to bind these objects together
target_link_libraries(main tools)
