/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23.nov.2020
 * @brief  Ejercicios propuestos en las prácticas de Informática Básica
 *         Ejercicio 2. Práctica 7:
 *         Se dice que una palabra es palíndroma si se lee igual de 
 *         derecha a izquierda que de izquierda a derecha. 
 *         Ejemplos de palíndromas son las palabras "Ana" o "arenera". 
 *         Desarrolle una función bool IsPalindrome(std::string my_string);
 *         que determine si la cadena que se le pasa como parámetro es palíndroma o no. 
 *         Realice un programa que inicialize un vector de N componentes cada una de 
 *         las cuales sea una cadena (std::string). 
 *
 *         Haga que el programa imprima en pantalla las N cadenas del vector, indicando para cada una de ellas si es palíndroma o no.
 *
 *         Versión 1: Partimos del programa strings.cc de los ejemplos de clase
 *                    Veamos cómo imprimir en pantalla los caracteres que componen una cadena (string)
 *         Versión 2: Imprimamos los caracteres pero en orden inverso
 *         Versión 3: Crearemos una nueva cadena con la cadena inversa
 *
 * @see https://github.com/fsande/IB-P07-Functions/blob/master/Functions.md
 * @see http://www.cplusplus.com/reference/string/string/length/
 */

#include <iostream>
#include <string>
#include <vector>


bool IsPalindrome(const std::string& cadena) {
  std::string cadena_inversa{""};
  for (int i = cadena.length() - 1; i >= 0; --i) {
    cadena_inversa += cadena[i];
  }
  if (cadena_inversa == cadena)
    return true;
  else 
    return false;
}

std::string Answer(const bool respuesta) {
  if (respuesta)
    return " - Sí";
  else
    return " - No";
}

int main () {
  const std::string kHello{"Hello"};
  std::vector<std::string> cadenas = {"ana", "Hello", "olo", "arroz"};
  for (auto cadena: cadenas) {
    std::cout << cadena << Answer(IsPalindrome(cadena)) << std::endl;
  }
  return 0;
}

