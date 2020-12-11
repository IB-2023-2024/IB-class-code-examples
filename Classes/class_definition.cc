/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief class definition example
 *
 * Class consists of zero or more members
 * Members can be of various types: data member, function member, and others (e.g., type member)
 * Data members define representation of object of class
 * Function members (also called member functions) provide operations on such objects
 * Interface is part of class that is directly accessible to its users
 * Implementation is part of class that its users access only indirectly through interface
 * Can control level of access that users of class have to its members
 * Three levels of access: private, protected, and public
 *    private: member can only be accessed by other members of class and friends of class
 *    public: member can be accessed by any code
 *    protected: relates to inheritance (discussion deferred until later)
 * public members constitute the class interface
 * private members constitute the class implementation
 *
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see http://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines#c-classes-and-class-hierarchies
 */

#include <iostream>

class Image {
 public:
  Image(const std::string& file_name);
  void Draw();      /// Function Member
 private:
  int rows_{0};    /// Data members
  int cols_{0};
};

// Implementation omitted here

int main() {
  Image image("some_image.jpg");
  image.Draw();
  return 0;
}
