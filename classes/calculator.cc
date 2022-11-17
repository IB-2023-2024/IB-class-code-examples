/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Jun 25 2020
 * @brief Calculator class
 *        In addition to member variables and member functions, 
 *        classes can have member types or nested types (including type aliases). 
 *        In this example, we’re creating a calculator where we can swiftly change 
 *        the type of number it’s using if we ever need to.
 *
 * @see https://www.learncpp.com/cpp-tutorial/82-classes-and-class-members/
 * @see https://www.learncpp.com/cpp-tutorial/typedefs-and-type-aliases/
 */

#include <iostream>
#include <vector>

class Calculator {
 public:
  using Number = int; /// this is a nested type alias

  Number Add(const Number summand1, const Number summand2) {
    auto result{summand1 + summand2};
    result_history_.push_back(result);
    return result;
  }

  void PrintHistory() {
    for (Number result : result_history_) {
      std::cout << result << std::endl;
    }
  }

 private:
  std::vector<Number> result_history_{};

};

int main() {
  Calculator calculator{};
  std::cout << calculator.Add(3, 4) << '\n'; // 7
  std::cout << calculator.Add(99, 24) << '\n'; // 123
  calculator.PrintHistory();
  return 0;
}
