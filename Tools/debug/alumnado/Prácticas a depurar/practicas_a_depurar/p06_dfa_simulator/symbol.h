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
 * @file symbol.h 
 * @brief Donde se aloja la declaración de la clase Symbol y la declaracion de
 * sus metodos. La clase Symbol contiene un std::string que será cada etiqueta
 * necesaria para transitar de un estado a otro del Dfa, también será un trozo
 * de una palabra o cadena que le será pasada al Dfa para que la analice, y
 * sepa, a que estado tiene que ir, partiendo desde el que está, con el Symbol
 * actual que tiene.
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

#ifndef _SYMBOL_
#define _SYMBOL_

#include <iostream>
#include <string>

/**
 * @class Symbol. 
 * @brief Para poder tratar con alfabetos con símbolos de longitud mayor a 1
 * (con un alfabeto que contenga el símbolo "hola" por ejemplo), necesitamos
 * definir que es un símbolo exactamente, lo que hace esta clase.
 */
class Symbol {
 public:
  /// Constructores. Tenemos 4, el por defecto, los dos predeterminados (los
  /// usamos más), y el de copia.
  Symbol(void);
  Symbol(const char& character);
  Symbol(const std::string& chain);
  Symbol(const Symbol& symbol);

  /// Setters.
  void SetSymbol(const char& character);
  void SetSymbol(const std::string& chain);
  void SetSymbol(const Symbol& symbol);
  void EmplaceBack(const char& character);
  void EmplaceBack(const std::string& chain);
  void EmplaceBack(const Symbol& symbol);

  /// Getters.
  std::string GetSymbol(void) const;

  /// Funciones de la clase (Métodos).
  size_t Size(void) const;

  /// Operadores sobrecargados.
  bool operator==(const Symbol& symbol) const;
  void operator=(const Symbol& symbol);
  void operator+=(const Symbol& symbol);
  Symbol operator+(const Symbol& symbol);
  bool operator<(const Symbol& symbol) const;

  /// Operadores de flujo de entrada y salida.
  friend std::ostream& operator<<(std::ostream& out, const Symbol& symbol);
  friend std::istream& operator>>(std::istream& input, Symbol& symbol);
  
 private:
  std::string symbol_; ///< std::string que actua como un símbolo.
};
#endif 

