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
 * @file chain.h 
 * @brief Donde se aloja la declaración de la clase Chain y la declaracion de
 * sus metodos. La clase Chain contiene una variable std::vector<Symbol> y cada
 * objeto de la clase será una palabra o cadena, que le pasaremos a nuestro Dfa
 * para que analice si es aceptada o rechazada.
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

#ifndef _CHAIN_
#define _CHAIN_

#include <vector>

#include "symbol.h"

/**
 * @class Chain.
 * @brief Para poder trabajar de forma más eficiente con las palabras que se le
 * pasan al programa dentro del archivo input.txt, está esta clase, cada objeto
 * simula una palabra que se le pasará al DFA, y este trabajará con sus
 * símbolos, porque si trabajara con caracteres directamente, estaríamos
 * obviando a los alfabetos con símbolos complejos (que mínimo uno de sus
 * símbolos, se representa con dos caracteres). 
 */
class Chain {
 public:
  /// Constructores. Tenemos 3, el por defecto, que es un vector vacío, el
  /// predeterminado y el de copia, usaremos más del por defecto.
  Chain(void);
  Chain(const std::vector<Symbol>& chain);
  Chain(const Chain& chain);

  /// Setters.
  void EmplaceBack(const char& symbol);
  void EmplaceBack(const std::string& symbol);
  void EmplaceBack(const Symbol& symbol);

  /// Getters.
  std::vector<Symbol> GetChain(void) const;
  Symbol At(const size_t& position) const;

  /// Funciones de la clase (Métodos).
  void Clear(void); ///< Vacía chain_ y tamaño = 0.
  size_t Size(void) const; ///< Devuelve el tamaño de chain_.

  /// Operadores sobrecargados.
  void operator=(const Chain& chain);
  bool operator==(const Chain& chain) const;
  Symbol operator[](const size_t& position) const;
  Chain operator+(const Chain& chain);

  /// Operadores de flujo de entrada y salida.
  friend std::ostream& operator<<(std::ostream& out, const Chain& chain);
  friend std::istream& operator>>(std::istream& input, Chain& chain);

 private:
  std::vector<Symbol> chain_; ///< Distinguimos cada símbolo y lo guardamos.
};
#endif
