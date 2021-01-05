/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Illustrates the behaviour of access specifiers with inheritance
 *        Private members can only be accessed by member functions of the 
 *        same class or friends. 
 *        This means derived classes can not access private members of the base class directly!
 *        The protected access specifier allows the class the member belongs to, friends, 
 *        and derived classes to access the member. 
 *        However, protected members are not accessible from outside the class.
 *
 *        Uncomment the commented lines to study the behaviour
 *
 * @see https://www.learncpp.com/cpp-tutorial/inheritance-and-access-specifiers/
 */

class Base {
 public:
  int public_; // can be accessed by anybody
 protected:
  int protected_; // can be accessed by Base members, friends, and derived classes
 private:
  int private_; // can only be accessed by Base members and friends (but not derived classes)
};

class Derived: public Base {
 public:
  Derived() {
    public_ = 1; // allowed: can access public base members from derived class
    protected_ = 2; // allowed: can access protected base members from derived class
    // private_ = 3; // not allowed: can not access private base members from derived class
  }
};

int main() {
  Base base;
  base.public_ = 1; // allowed: can access public members from outside class
  // base.protected_ = 2; // not allowed: can not access protected members from outside class
  // base.private_ = 3; // not allowed: can not access private members from outside class
}
