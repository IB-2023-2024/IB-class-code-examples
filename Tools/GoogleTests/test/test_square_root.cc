#include <gtest/gtest.h>

#include "square_root.h"

TEST(SquareRootTest, PositiveNos) { 
  ASSERT_EQ(6, SquareRoot(36.0));
  ASSERT_EQ(18.0, SquareRoot(324.0));
  ASSERT_EQ(25.4, SquareRoot(645.16));
  ASSERT_EQ(0, SquareRoot(0.0));
}

TEST(SquareRootTest, NegativeNos) {
  ASSERT_EQ(-1.0, SquareRoot(-15.0));
  ASSERT_EQ(-1.0, SquareRoot(-0.2));
}
