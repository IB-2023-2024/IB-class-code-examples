/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 30 Jun 2020
 * @brief Class constructor
 *
 * @see http://www.cplusplus.com/doc/tutorial/classes2/#default_constructor
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see http://www.cplusplus.com/doc/tutorial/classes2/
 */

#include <iostream>

using namespace std;

class Vector {          // Two-dimensional vector class
  public:
    Vector() {          // Default constructor
      x_ = 0.0;
      y_ = 0.0;
			cout << "Class constructor has been called" << endl;
    }
  // ...
  private:
    double x_ ;         // The x component of the vector
    double y_ ;         // The y component of the vector
};

int main() {
  cout << "Previous to object declaration" << endl;
  Vector my_vector1;      // calls Vector(); my_vector1 set to (0,0)
  cout << "After object declaration" << endl;
  Vector Func();          // declares function Func that returns Vector
	return 0;
}
