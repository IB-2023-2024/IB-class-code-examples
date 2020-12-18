# include <gtest/gtest.h>

# include "factorial.h"

TEST(IntegerFunctionTest, negative) {
        EXPECT_EQ(1, Factorial(-5));
        EXPECT_EQ(1, Factorial(-1));
        EXPECT_GT(Factorial(-10), 0);
}

TEST(IntegerFunctionTest, DISABLED_zero) {
         EXPECT_EQ(1, Factorial(0));
}

TEST(IntegerFunctionTest, positive) {
         EXPECT_EQ(1, Factorial(1));
         EXPECT_EQ(2, Factorial(2));
         EXPECT_EQ(6, Factorial(3));
         EXPECT_EQ(40320, Factorial(8));
}    
