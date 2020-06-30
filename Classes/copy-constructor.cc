/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 30 Jun 2020
 * @brief Copy constructor
 *
 * @see http://www.cplusplus.com/doc/tutorial/classes2/#copy_constructor
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

		Vector(const Vector& v) { // Copy constructor
      x_ = v.x_; 
			y_ = v.y_;
			cout << "Copy constructor has been called" << endl;
    }

  // ...

  private:
    double x_ ;         // The x component of the vector
    double y_ ;         // The y component of the vector
};

int main() {
  cout << "Previous to object v declaration" << endl;
	Vector v;
  cout << "After object v declaration" << endl;
  Vector w(v);         // calls Vector(const Vector&)
  Vector u = v;        // calls Vector(const Vector&)
	return 0;
}

