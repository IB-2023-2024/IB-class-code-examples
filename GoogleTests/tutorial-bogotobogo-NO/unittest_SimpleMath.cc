// unittest_SimpleMath.cc : Defines the entry point for the console application.

#include <gtest/gtest.h>
#include "simplemath.h"

TEST(testMath, myCubeTest)
{
    EXPECT_EQ(1000, cubic(10));	
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
