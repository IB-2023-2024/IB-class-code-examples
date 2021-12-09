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
 * @file set_status.h 
 * @brief Donde se aloja la declaración de la clase SetStatus y la declaracion
 * de sus metodos. La clase SetStatus contiene un std::set<size_t> y cada
 * elemento de este conjunto, representará un estado del conjunto de estados de
 * un Dfa (sea el conjunto de estados totales y/o de aceptación), su longitud
 * será la cantidad de estados que tiene el conjunto, y cada elemento del
 * conjunto será un número (no negativo) que representará el nombre o
 * identificador del estado, usamos un std::set<size_t> porque los estados
 * no se pueden repetir.
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
 *
 */

#ifndef _SET_STATUS_
#define _SET_STATUS_

#include <iostream>
#include <set>
#include <sstream>

/**
 * @class SetStatus.
 * @brief Dos elementos importantes de un DFA son el conjunto de estados de
 * todo el DFA, y el conjunto de estados de aceptación, esta clase se encarga
 * de definirlos y usarlos según convenga.
 */
class SetStatus {
 public:
  /// Constructores. Tenemos 5 constructores, el predeterminado y el que usamos
  /// cuando solo queremos darle un nombre al conjunto (los más usados), el que
  /// nos permite enumerar estados desde el cero hasta un número que decidamos,
  /// (también usado), el que nos permite pasarle un vector con estados ya
  /// puestos y el de copia.
  SetStatus(void);
  SetStatus(const std::string& name);
  SetStatus(const std::string& name, const size_t& num_status);
  SetStatus(const std::string& name, const std::set<size_t>& status);
  SetStatus(const SetStatus& status);

  /// Setters.
  void Insert(const size_t& state);
  void SetSet(const std::set<size_t>& status);
  void SetSet(const SetStatus& status);
  void SetName(const char& name);
  void SetName(const std::string& name);

  /// Getters.
  int At(const size_t& position) const;
  std::string GetName(void) const;
  std::set<size_t> GetSetStatus(void) const;

  /// Funciones de la clase (Métodos).
  bool IsItAState(const size_t& num) const;
  void Clear(void);

  /// Operadores sobrecargados.
  void operator=(const SetStatus& set_status);
  int operator[](const size_t& state) const;

  /// Operador de flujo de salida.
  friend std::ostream& operator<<(std::ostream& out, const SetStatus& status);

 private:
  std::string name_; ///< Nombre del conjunto de estados, para diferenciarlos.
  std::set<size_t> set_status_; ///< Conjunto de estados.
};
#endif
