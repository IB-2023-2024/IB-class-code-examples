#include <limits.h>
#include <gtest/gtest.h>

#include "Multiply.h"
 
class MultiplyTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }
 
  virtual void TearDown() {
  }
};
 
TEST_F(MultiplyTest,twoValues){
    const int x = 4;
    const int y = 5;
    Multiply multiply;
    EXPECT_EQ(20,multiply.twoValues(x,y));
    EXPECT_EQ(6,multiply.twoValues(2,3));
}
