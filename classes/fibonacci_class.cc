/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 08 Nov 2020
 * @brief OOP Fibonacci. 
 *        Computes the sum of all even tems under 1000 of the Fibonacci sequence
 *        Project Euler #2
 *        Note: This is rather advanced code for a beginner
 *        FibonacciGenerator overloads the function call operator
 *        Visualize the execution to clarify: 
 *
 * @see https://en.wikipedia.org/wiki/Fibonacci_number
 * @see https://projecteuler.net/problem=2
 * @see https://medium.com/@TheZaki/project-euler-2-even-fibonacci-numbers-2219e9438970
 * @see https://stackoverflow.com/questions/21360694/sum-of-even-fibonacci-numbers-under-1000
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 * @see Functors https://www.learncpp.com/cpp-tutorial/99-overloading-the-parenthesis-operator/
 */

#include <iostream>

// The constructor uses an initialization list (variables after the colon) 
// @see https://stackoverflow.com/questions/2785612/c-what-does-the-colon-after-a-constructor-mean
// Overloads the function call operator:
// @see https://www.tutorialspoint.com/cplusplus/function_call_operator_overloading.htm
// The class holds the values of Three terms of the sequence: f0, f1, f2
// On each call to the overloaded function it returns f0 and updates f1 and f2
//
class FibonacciGenerator {
 public:
  FibonacciGenerator(): f0_{0}, f1_{1} {}
  int operator()() {
    int f2{f0_ + f1_};  // computes a new term to be returned 'in the future'
    f0_ = f1_;   
    f1_ = f2;
    return f0_;
  }
 private:
  int f0_;  // Term to be returned on each call
  int f1_;  // Next term to be returned
};

int main() {
  const int kLimit{1000};

  FibonacciGenerator fibgen;
  int sum = 0;
  for(int term = fibgen(); term < kLimit; term = fibgen()) {
    if(term % 2 == 0) 
      sum += term;
  }
  std::cout << sum << std::endl;
}
