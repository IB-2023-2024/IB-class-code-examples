# include <gtest/gtest.h>

# include "cubic.h"

TEST(testMath, myCubeTest) {
    EXPECT_EQ(1000, Cubic(10));	
}
