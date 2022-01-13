/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 13 Jan 2022
 * @brief implicit parameter this
 *        Calling a class method from another chass method using this
 *
 * Member functions always has object of class as implicit parameter
 * Implicit parameter passed in form of pointer using special variable called this
 *
 * @see https://stackoverflow.com/a/27087502/12791643
 */

#include <iostream>

class MyClass {
 public:
  void Display() {
    std::cout << "Value: " << value_ << std::endl;       // Display can directly access the value_ atribute
    std::cout << "Value: " << this->value_ << std::endl; // Equivalently it could access also using the this pointer
    std::cout << "Square of Value: " << this->Square() << std::endl;  // Can also call methods on the this object
    std::cout << "Cube of Value: " << this->Cube() << std::endl;
  }
 private:
  int Square() { return value_ * value_; }
  int Cube() { return value_ * value_ * value_; }
  int value_{2};     // Data member initialization
};

int main() {
  MyClass my_object;
  my_object.Display();  // Prints the Object information
  return 0;
}
