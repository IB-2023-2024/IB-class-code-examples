/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 7.nov.2020
 * @brief This file declares the "Help Text" constant and two functions
 *
 */

#include <iostream>

const std::string kHelpText = "Este programa calcula la suma de todos los términos pares de la \
serie de Fibonacci que sean menores que un valor, que el usuario \
ha de introducir por línea de comandos para la ejecución del programa";

void Usage(int argc, char *argv[]);
size_t fibonacci_sum(const size_t kLimit);
