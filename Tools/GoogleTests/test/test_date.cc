#include <gtest/gtest.h>

#include "multiply.h"
 
TEST(DateTest, twoValues){
    Date d1{2020, 12, 1};
    Date d2{2020, 12, 1};

    EXPECT_EQ(20, multiply.TwoValues(x, y));
    EXPECT_EQ(6, multiply.TwoValues(2, 3));
}



  Date today{2020, 12, 1};  // initialize using parameterized constructor (C++11)
  const Date date1{};               // initialize using default constructor
  const Date date2{2020, 1, 18}; 
  const Date date3{2020, 12, 18}; 
	if (date3 > date2) {
	  std::cout << date3 << " > " << date2 << std::endl;
	}
	else
	{
	  std::cout << date3 << " <= " << date2 << std::endl;
	}
	std::cout << "Date: " << date2 << std::endl;
  return 0;
}
