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
 *
 * @see https://github.com/fsande/IB-P07-Functions/blob/master/Functions.md
 * @see http://www.cplusplus.com/reference/string/string/length/
 */

#include <iostream>
#include <string>

void PrintCharsInString(const std::string& cadena) {
  for (size_t i = 0; i < cadena.length(); ++i) {
    std::cout << i << " - " << cadena[i] << std::endl;
  }
}

int main () {
  const std::string kHello{"Hello"};

  std::cout << "Type your name:" << std :: endl;
  std::string name = "";   // Init empty 
  std::cin >> name;
  // Read name
  std::cout << kHello + ", " + name + "!" << std::endl;

  PrintCharsInString(kHello); 

  return 0;
}
