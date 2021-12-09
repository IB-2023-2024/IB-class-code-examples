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
 * @file trans_func.h 
 * @brief Donde se aloja la declaración de la clase TransFunc y la declaracion
 * de sus metodos. La clase TransFunc tiene un std::vector<std::vector<size_t>>
 * que es una matriz que actua como tabla de transiciones, ahí guardamos todas
 * las posibles transiciones que tiene nuestro Dfa desde cada uno de sus
 * estados, y también tiene un atributo especial que es un
 * std::vector<std::string>> que coge los simbolos del alfabeto del Dfa, y su
 * posición relativa desde el inicio de este, la guarda en orden, de modo que
 * sin importar que simbolos tengamos en el alfabeto, podemos colocarle una
 * columna en la matriz según su orden en el alfabeto.
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

#ifndef _TRANS_FUNC_
#define _TRANS_FUNC_

#include <iostream>
#include <string>
#include <vector>

#include "symbol.h"

/**
 * @class TransFunc.
 * @brief Contiene la tabla de transición que usará nuestro DFA para saber cual
 * es el estado siguiente al que hay que transitar. 
 */
class TransFunc {
 public:
  /// Constructores.
  TransFunc(void); 
  TransFunc(const int& num_status);
  TransFunc(const TransFunc& trans_func);

  /// Setters.
  void AddSymbol(const Symbol& symbol);
  /// Si se devuelve true, ha habido un error a la hora de asignar el estado.
  bool AddState(const int& state);
  bool AddTransition(const int& state, const Symbol& symbol, 
                     const int& next_state);

  /// Getters.
  int NextState(const int& state, const Symbol& symbol) const;

  /// Funciones de la clase (Métodos).
  bool IsItADfa(void) const;
  bool IsItInConversionTable(const Symbol& symbol) const;
  bool IsItAState(const int& state) const;
  size_t Size(void) const;

  /// Operadores sobrecargados.
  void operator=(const TransFunc& trans_func);

  /// Operador de flujo de salida.
  friend std::ostream& operator<<(std::ostream& out, const TransFunc& trans_func);

 private:
  std::vector<std::vector<int>> trans_func_; ///< Función de transición.
  /// Convierte símbolos a números, así sabemos que símbolo se asocia con una 
  /// determinada columna en nuestra tabla, uso un vector y no un set, porque
  /// yo le voy a asociar un simbolo a cada columan de la tabla, y si usara un
  /// std::set<Symbol>, entoces los simbolos no los ordeno yo, y eso podría 
  /// ocasionar que las columnas no se correspondan con los simbolos.
  std::vector<Symbol> conversion_table_;
};
#endif
