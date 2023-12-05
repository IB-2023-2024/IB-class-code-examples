/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Jan 5 2021
 * @brief Illustrates public inheritance
 *        Public inheritance means:
 *        - Public inherited members stay public (so public_ is treated as public)
 *        - Protected inherited members stay protected (so protected_ is treated as protected)
 *        - Private inherited members stay inaccessible (so private_ is inaccessible)
 *
 * @see https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers/
 */

class Base {
 public:
  int public_;
 protected:
  int protected_;
 private:
  int private_;
};

class Derived: public Base { // note: public inheritance
 public:
  Derived() {
    public_ = 1; // okay: public_ was inherited as public
    protected_ = 2; // okay: protected_ was inherited as protected
    private_ = 3; // not okay: private_ is inaccessible from derived class
  }
};

int main() {
  // Outside access uses the access specifiers of the class being accessed.
  Base base;
  base.public_ = 1; // okay: public_ is public in Base
  base.protected_ = 2; // not okay: protected_ is protected in Base
  base.private_ = 3; // not okay: private_ is private in Base

  Derived derived;
  derived.public_ = 1; // okay: public_ is public in Derived
  derived.protected_ = 2; // not okay: protected_ is protected in Derived
  derived.private_ = 3; // not okay: private_ is inaccessible in Derived
}
