/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Christopher Expósito
 * @date 23.nov.2020
 * @brief Declaración de las funciones que intervienen en el programa
 * @see https://github.com/fsande/IB-P07-Functions/blob/master/Functions.md
 */

#include <iostream>
#include <string>

const std::string kHelpText = "Este programa solicita al usuario un número e imprime en pantalla todos los números primos menores que el introducido";

void Usage(int argc, char* argv[]);
bool IsPrime(int numberToCheck);
