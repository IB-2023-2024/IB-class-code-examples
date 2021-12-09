/** 
 * Universidad de La Laguna (ULL)
 * Escuela Superior de Ingenieria y Tecnologia (ESIT)
 * Grado en Ingenieria Informatica
 * Asignatura: Computabilidad y Algoritmia
 * Curso: 2º
 * Practica 6: Simulacion de DFA's (Autómatas Finitos Deterministas)
 * @author Cristopher Manuel Afonso Mora
 * Correo: alu0101402031@ull.edu.es
 * @date 05/11/2021
 * 
 * @file dfa.h 
 * @brief Donde se aloja la declaración de la clase Dfa y la declaracion de sus
 * metodos. La clase Dfa contiene 5 atributos privados y son:
 * Un objeto Alphabet, dos SetStatus, uno TransFunc, y un size_t, este último
 * el size_t, representará el estado inicial del Dfa, a un objeto Dfa,
 * hay que pasarle uno Chain, y el Dfa analizará al objeto Chain y devolverá
 * un resultado diciendo si ha aceptado al objeto Chain o lo ha rechazado.
 *
 * @bug No hay bugs conocidos
 * 
 * Referencias: Enlaces de Interes
 * @see 
 * 
 * @version 1.0
 * @brief Historial de Revisiones 
 * 05/11/21 - Creacion (primera version) del codigo:
 *            Solo he creado el archivo, le he puesto el comentario de
 *            cabecera y declarado su include 
 * 08/11/21 - He terminado la clase y sus métodos.
 */

#ifndef _DFA_
#define _DFA_

#include <fstream>

#include "alphabet.h"
#include "chain.h"
#include "set_status.h"
#include "trans_func.h"

/**
 * @class Dfa.
 * @brief Clase que imitará el funcionamiento de un Dfa que le pasaremos su
 * definición por medio de un archivo. 
 */
class Dfa {
 public:
  /// Constructores. Tenemos 3, el por defecto, el que creamos nosotros 
  /// (que lo usaremos más) y el de copia.
  Dfa(void);
  Dfa(std::ifstream& dfa_def);
  Dfa(const Dfa& dfa);

  /// Getters.
  Alphabet GetAlphabet(void) const;
  SetStatus GetAllStatus(void) const;
  int GetInitialState(void) const;
  SetStatus GetAceptationStatus(void) const;
  TransFunc GetTransFunc(void) const;
  bool Fail(void) const;

  /// Funciones de la clase (Métodos).
  bool IsItInAlphabet(const Chain& chain) const;
  bool EvalStr(const Chain& chain) const;
  void EvalStrInFile(std::ifstream& input, std::ofstream& out) const;

  /// Operador de flujo de salida.
  friend std::ostream& operator<<(std::ostream& out, const Dfa& dfa);

 private:
  Alphabet alphabet_; ///< Alfabeto del DFA.
  SetStatus all_status_; ///< Conjunto de estados totales.
  int initial_state_; ///< Estado inicial del Dfa.
  SetStatus aceptation_status_; ///< Conjunto de estados de aceptación.
  TransFunc trans_func_; ///< Función de Transición del Dfa.

  bool creation_failed_; ///< Nos dice si el archivo ".dfa" está correcto.
};
#endif
