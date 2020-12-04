cmake_minimum_required(VERSION 2.4)

project(hello_world)

include_directories(${PROJECT_SOURCE_DIR})
add_library(applib foo.cc)
add_executable(app main.cc)
target_link_libraries(app applib)
