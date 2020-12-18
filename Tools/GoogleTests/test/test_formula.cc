#include <gtest/gtest.h>

#include "formula.h"

TEST(blaTest, test1) {
    EXPECT_EQ (Formula::Bla (0),  0);
    EXPECT_EQ (Formula::Bla (10), 20);
    EXPECT_EQ (Formula::Bla (50), 100);
}
