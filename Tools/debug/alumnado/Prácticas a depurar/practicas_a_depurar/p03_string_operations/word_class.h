// Universidad de La Laguna
// Escuela Superior de Ingenieria y Tecnologia
// Grado en Ingenieria Informatica
// Asignatura: Computabilidad y Algoritmia
// Curso: 2º
// Practica 3: Operaciones con cadenas y lenguajes
// Autor: Cristopher Manuel Afonso Mora
// Correo: alu0101402031@ull.es
// Fecha: 17/10/2021
// Archivo word_class.h: Donde se aloja la declaración de la clase
//         cadena y la declaracion de sus metodos
//
// Referencias:
//         Enlaces de interes

#ifndef _WORD_CLASS_
#define _WORD_CLASS_

#include <vector>

#include "symbol_class.h"

class Word {
 public:
  //Constructores
  Word(void);
  Word(std::vector<Symbol>& word);
  Word(Word& word);

  //Setters y Getter
  void SetWord(std::vector<Symbol>& word);
  void SetWord(Word& word);
  std::vector<Symbol> GetWord(void);
  Symbol GetSymbol(int& position);

  //Funciones
  std::string ShowWord(void); //Muestra la palabra por pantalla
  //Añadimos un simbolo más al objeto, concretamente al final
  void EmplaceBackOfWord(std::string& symbol);
  void EmplaceBackOfWord(Symbol& symbol);
  void ClearWord(void); //Vacía el vector word_
  size_t SizeWord(void); //Devuelve el tamaño del vector word_
  std::vector<Word> Power(int& power);

  //Operadores
  void operator=(Word& word);
  bool operator==(Word& word);
  Word operator+(Word& word);

  //Operadores de Flujo de entrada y salida
  friend std::ostream& operator<<(std::ostream& output, Word& word);
  friend std::istream& operator>>(std::istream& input, Word& word);

 private:
 // Donde guardamos la cadena a evaluar
  std::vector<Symbol> word_;
};

#endif
