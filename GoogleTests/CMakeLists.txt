project(4-GC++)
cmake_minimum_required(VERSION 2.6)
 
# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
 
# Link runTests with what we want to test and the GTest and pthread library
add_executable(executeTests sqrt_test.cc)
target_link_libraries(executeTests ${GTEST_LIBRARIES} pthread)







#set(BOOST_THREAD_LIBRARY "/usr/lib/x86_64-linux-gnu/libpthread.so")
#MESSAGE( [Main] " BOOST_THREAD_LIBRARY = ${BOOST_THREAD_LIBRARY}")

# Link runTests with what we want to test and the GTest and pthread library
#add_executable(runTests tests.cc)
#target_link_libraries(runTests ${GTEST_LIBRARIES} ${BOOST_THREAD_LIBRARY})
#target_link_libraries(runTests gtest pthread)
