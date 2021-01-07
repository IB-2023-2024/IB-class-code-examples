/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief implicit parameter this
 *
 * Member functions always has object of class as implicit parameter
 * Implicit parameter passed in form of pointer using special variable called this
 * Normally, we do not explicitly write “this”, however
 *
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see http://www.cplusplus.com/doc/tutorial/templates/#this
 * @see https://en.cppreference.com/w/cpp/language/this
 */

class MyClass {
 public:
  int UpdateValue(int newValue) {
    int oldValue = value_;
    value_ = newValue;    // "value_" means "this->value_"
    return oldValue;
  }
 private:
  int value_;      // Data member
};

void Func() {
  MyClass my_object;
  my_object.UpdateValue(5);
  // in MyClass::UpdateValue, variable this equals &my_object
}

int main() {
  Func();
  return 0;
}
