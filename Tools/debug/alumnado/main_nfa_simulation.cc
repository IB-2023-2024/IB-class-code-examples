/**
* Universidad de La Laguna
* Escuela Superior de Ingeniería y Tecnología
* Grado en Ingeniería Informática
* Asignatura: Computabilidad y Algoritmia
* Curso: 2º
* Práctica 7: NFA simulation
* Autor: Sergio Perera Márquez
* Correo: alu0101394503@ull.edu.es
* Fecha de creación: 14/10/2021
* Referencias:  https://google.github.io/styleguide/cppguide.html
* Ejecutar: ./p07_nfa_simulation ejemplo.nfa cadenas.txt cadenas_modificadas.txt
*/
#include <iostream>
#include <fstream>

#include "main_functions.h"
#include "nfa.h"

int main (int argc, char *argv[]){

  Usage (argc, argv);
  
  //Recogemos los argumentos de la línea de comandos
  std::string input_nfa {argv[1]};
  std::string input_txt {argv[2]};
  std::string output_txt {argv[3]};

  Nfa nfa {input_nfa, input_txt, output_txt};

  std::cout << "\nImprimo nfa:\n" << nfa;
  
  nfa.Recognize();


  return(0);
}
