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
*/
#include <iostream>
#include <fstream>
#include <vector>
#include "main_functions.h"

const std::string kProgramText {"\nEste programa realiza un NFA partiendo de un"
  " archivo dado y al pasar un archivo con cadenas este dice si son aceptadas"
  " por el NFA o no"
  "\nImprimiendo resultados en el fichero de salida: "};

// Esta función la usaremos para comprobar que el usuario ejecute correctamente 
// el programa
void Usage (int argc, char *argv[]) {
  //Hacemos que help sea una posición menos para que no de error de puntero nulo
  std::string help {argv[argc-1]};
  
  if (help == "--help") {
    manual();
    exit(EXIT_SUCCESS);
  }    
  else if (argc < 3) { 
    std::cout << "Faltan argumentos, pruebe ./nfa_simulation --help " << 
    "para más información" << std::endl;
    exit(EXIT_SUCCESS);
  }
  
  std::cout << kProgramText << argv[3] << "\n" << std::endl;
}

void manual(){
  std::cout << "El programa se ejecuta de la siguiente manera: " << 
  "./nfa_simulation input.nfa input.txt output.txt" << std::endl;
}
