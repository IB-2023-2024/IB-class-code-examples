/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 8 Jun 2020
 * @brief C++ continue statement
 * 
 * The continue statement causes the program to skip the rest of the loop in 
 * the current iteration, as if the end of the statement block had been reached, 
 * causing it to jump to the start of the following iteration. 
 *
 * break leaves a loop, even if the condition for its end is not fulfilled. 
 * It can be used to end an infinite loop, or to force it to end before its natural end. 
 * For example, let's stop the countdown before its natural end:
 * @see http://www.cplusplus.com/doc/tutorial/control/
 */

# include <iostream>
# include <string>

int main () {
  const int kNumberOfIterations{10};  // Play modifying this value

  // Let's skip number 5 in our countdown:
  for (int i = kNumberOfIterations; i > 0; i--) {
    if (i == 5) continue;
      std::cout << i << ", ";
  }
  std::cout << "liftoff!" << std::endl;

  // Let's stop the countdown before its natural end:
  for (int i = kNumberOfIterations; i > 0; i--) {
    std::cout << i << ", ";
    if (i == 3) {
      std::cout << "countdown aborted!";
      break;
    }
  }
}
