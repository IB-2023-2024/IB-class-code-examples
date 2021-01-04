/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief Using STL
 *        You have already been using classes without knowing it
 *        The C++ standard library is full of classes that have been created for your benefit. 
 *        std::string, std::vector, and std::array are all class types! 
 *        So when you create an object of any of these types, you’re instantiating a class object
 *        And when you call a function using these objects, you’re calling a member function
 *
 * @see https://www.learncpp.com/cpp-tutorial/82-classes-and-class-members/
 */

#include <string>
#include <array>
#include <vector>
#include <iostream>
 
int main() {
  std::string my_string{ "Hello, world!" };   /// instantiate a string class object
  std::array<int, 3> my_array{ 1, 2, 3 };   /// instantiate an array class object
  std::vector<double> my_vector{ 1.1, 2.2, 3.3 };   /// instantiate a vector class object
  std::cout << "length: " << my_string.length() << '\n';   /// call a member function
  return 0;
}
