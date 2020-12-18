/**
 *  @see https://stackoverflow.com/questions/26030700/unit-testing-c-setup-and-teardown
 */

#include <gtest/gtest.h>

#include "addition.h"
 
class AdditionTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }
 
  virtual void TearDown() {
    // Code here will be called immediately after each test
    // (right before the destructor).
  }
};
 
TEST_F(AdditionTest, twoValues){
    const int x = 4;
    const int y = 5;
    Addition addition;
    EXPECT_EQ(9, addition.TwoValues(x, y));
    EXPECT_EQ(5, addition.TwoValues(2, 3));
}
