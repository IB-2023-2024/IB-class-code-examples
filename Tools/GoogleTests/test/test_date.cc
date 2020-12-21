#include <gtest/gtest.h>

#include "date.h"
 
TEST(DateTest, greater){
    Date d1{2020, 12, 1};
    Date d2{2020, 12, 2};
    Date d3{2020, 11, 1};

    EXPECT_EQ(true, d2 > d1);
    EXPECT_EQ(false, d3 > d1);
}

TEST(DateTest, equal){
    Date d1{2020, 12, 1};
    Date d2{2020, 12, 1};

    Date d3{2020, 12, 2};
    Date d4{2020, 11, 1};
    Date d5{2019, 12, 1};

    EXPECT_EQ(true, d1 == d2);
    EXPECT_EQ(false, d1 == d3);
    EXPECT_EQ(false, d1 == d4);
    EXPECT_EQ(false, d1 == d5);
}
