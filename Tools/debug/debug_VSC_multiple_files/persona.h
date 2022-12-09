/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 13 2021
 * @brief Person class Definition
 *
 * @see https://www.learncpp.com/cpp-tutorial/header-guards/
 */

#ifndef PERSONA_H
#define PERSONA_H

#include <string>

/**
 * Clase Persona. 
 *       Representa una persona usando su nombre, apellidos y edad
 */
class Persona {
 public:
  Persona();
  Persona(const std::string& nombre, const std::string& apellido, const int edad);
  std::string nombre() const { return nombre_; }
  std::string apellido() const { return apellido_; }
  int edad() const { return edad_; }
  void Print() const;
 private:
  std::string nombre_{""};     /** Nombre de la persona */
  std::string apellido_{""};   /** Apellido de la persona */
  int edad_{0};                /** Edad de la persona */
};
 
#endif
