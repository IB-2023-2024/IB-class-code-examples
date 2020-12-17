/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 30 Jun 2020
 * @brief const after function states that this function does not change the object
 * Mark all functions that should not change the state of the object as const
 * Ensures that we can pass objects by a const reference and still call their functions
 * Substantially reduces number of errors
 *
 * In this example, the count() method does not change the object
 * Therefore it should be qualified const
 *
 * @see http://www.cplusplus.com/doc/tutorial/templates/#const_member_functions
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see https://isocpp.org/wiki/faq/const-correctness
 * @see https://www.learncpp.com/cpp-tutorial/810-const-class-objects-and-member-functions/
 */

#include <iostream>

class Counter {
 public:
  Counter(int newCount) {
    count_ = newCount;
  }
  int count() const { return count_; }  // note addition of const keyword after parameter list, but before function body
  void IncrementCount() { ++count_; }
 private:
  int count_{0};
};

void Func () {
  Counter my_counter{0};            // An instance of the class
  int my_value = my_counter.count();

  const Counter& my_counter2 = my_counter;
  my_value = my_counter2.count();      // If count() is not const you get an error: count() better be const!
}

int main() {
  Func();
  return 0;
}
