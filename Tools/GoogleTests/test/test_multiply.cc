/**
 *  @see https://stackoverflow.com/questions/26030700/unit-testing-c-setup-and-teardown
 */

#include <gtest/gtest.h>

#include "multiply.h"
 
class MultiplyTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }
  
  virtual void TearDown() {
  }
};
 
TEST_F(MultiplyTest, twoValues){
    const int x = 4;
    const int y = 5;
    Multiply multiply;
    EXPECT_EQ(20, multiply.TwoValues(x, y));
    EXPECT_EQ(6, multiply.TwoValues(2, 3));
}
