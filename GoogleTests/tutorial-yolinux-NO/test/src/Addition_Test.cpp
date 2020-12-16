#include <limits.h>
#include <gtest/gtest.h>

#include "Addition.h"
 
class AdditionTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }
 
  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};
 
TEST_F(AdditionTest,twoValues){
    const int x = 4;
    const int y = 5;
    Addition addition;
    EXPECT_EQ(9,addition.twoValues(x,y));
    EXPECT_EQ(5,addition.twoValues(2,3));
}
