/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 18 Dec 2020
 * @brief Tests Unitarios con la plataforma gtest
 *        Definición de la función Factorial que calcula el factorial de n
 *
 */

int Factorial(int n) {
  int result{1};
  for (int i = 1; i <= n; ++i) {
    result *= i;
  }
  return result;
}
