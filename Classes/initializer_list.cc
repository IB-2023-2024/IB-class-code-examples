/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 09 Dec 2020
 * @brief Constructor member initializer lists
 *        C++ provides a method for initializing class member variables 
 *        (rather than assigning values to them after they are created) via 
 *        a member initializer list (often called a “member initialization list”)
 *
 *        Using an initialization list is almost identical to doing direct 
 *        initialization or uniform initialization
 *
 *        The member initializer list is inserted after the constructor parameters. 
 *        It begins with a colon (:), and then lists each variable to initialize along 
 *        with the value for that variable separated by a comma.
 * 
 *        Note that we no longer need to do the assignments in the constructor body, 
 *        since the initializer list replaces that functionality. 
 *        Also note that the initializer list does not end in a semicolon.
 *
 * @see https://www.learncpp.com/cpp-tutorial/8-5a-constructor-member-initializer-lists/
 */

#include <iostream>

class Something {
 private:
  int value1_;
  double value2_;
  char value3_;

 public:
  Something(int value1, double value2, char value3 = 'c')
     : value1_{ value1 }, value2_{ value2 }, value3_{ value3 } { // directly initialize our member variables
  // No need for assignment here
  }

  void Print() {
   std::cout << "Something(" << value1_ << ", " << value2_ << ", " << value3_ << ")\n";
  }
};

int main() {
  Something something{ 1, 2.2 }; // value1 = 1, value2=2.2, value3 gets default value 'c'
  something.Print();
  return 0;
}
