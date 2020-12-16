// unittest_SimpleMath.cc : Defines the entry point for the console application.

#include <gtest/gtest.h>
#include "simplemath.h"

TEST(testMath, myCubeTest)
{
    EXPECT_EQ(1000, cubic(10));	
}
