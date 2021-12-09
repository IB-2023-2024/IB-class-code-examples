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
 * @file alphabet.h 
 * @brief Donde se aloja la declaración de la clase Alphabet y la declaracion
 * de sus metodos. La clase Alphabet contiene un std::set<Symbol> que será la
 * variable que usaremos a modo de alphabeto en la clase Dfa.
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
 * 07/11/21 - Clase terminada.
 * 
 */

#ifndef _ALPHABET_
#define _ALPHABET_

#include <set>

#include "symbol.h"

/**
 * @class Alphabet.
 * @brief Uno de los 5 elementos de un DFA es el alfabeto, esta clase se
 * encarga de definirlo y usarlo según sea conveniente. 
 */
class Alphabet {
 public:
  /// Constructores. Tenemos 4, el por defecto, al que solo le pasamos el
  /// nombre (el que más usamos), y los dos de copia.
  Alphabet(void);
  Alphabet(const std::string& name);
  Alphabet(const std::string& name, const std::set<Symbol>& alphabet);
  Alphabet(const Alphabet& alphabet);

  /// Setters.
  void Insert(const char& symbol);
  void Insert(const std::string& symbol);
  void Insert(const Symbol& symbol);
  void SetAlphabet(const std::string& name, const std::set<Symbol>& alphabet);
  void SetAlphabet(const Alphabet& alphabet);
  void SetName(const std::string& name);

  /// Getters.
  Symbol At(const size_t& position) const;
  std::set<Symbol> GetAlphabet(void) const;
  std::string GetName(void) const;

  /// Funciones de la clase (Métodos).
  bool IsItInAlphabet(const char& symbol) const;
  bool IsItInAlphabet(const std::string& symbol) const;
  bool IsItInAlphabet(const Symbol& symbol) const;
  size_t Size(void) const;
  void Clear(void);

  /// Operadores sobrecargados.
  void operator=(const Alphabet& alphabet);
  bool operator==(const Alphabet& alphabet) const;
  Symbol operator[](const size_t position) const;

  /// Operadores de flujo de entrada y salida.
  friend std::ostream& operator<<(std::ostream& out, const Alphabet& alphabet);
  friend std::istream& operator>>(std::istream& input, Alphabet& alphabet);

 private:
  std::string name_; ///< Nombre del alfabeto, para diferenciarlos entre sí.
  std::set<Symbol> alphabet_; ///< Varriable donde guardamos el alfabeto.
};
#endif
