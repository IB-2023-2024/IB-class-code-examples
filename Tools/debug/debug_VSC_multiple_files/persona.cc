/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 13 2021
 * @brief Persona class Implementation
 *
 * @see https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/
 */

#include <iostream>
#include <string>

#include "persona.h"

/*
 * @brief constructor por defecto
 */
Persona::Persona() : nombre_{"Alan"}, apellido_{"Turing"}, edad_{41} {
 std::cout << "DEBUG: Constructor Persona por DEFECTO ejecutado" << std::endl;
}

/*
 * @brief constructor with parameters
 * @param[in] nombre: string con el nombre de la persona a crear
 * @param[in] apellido: string con el apellido de la persona a crear
 * @param[in] edad: edad de la persona a crear
 */
Persona::Persona(const std::string& nombre, const std::string& apellido, const int edad) : nombre_{nombre}, apellido_{apellido}, edad_{edad} {
 std::cout << "DEBUG: Constructor persona ejecutado" << std::endl;
}

/*
 * @brief Inprime en pantalla los atributos
 * @param[in] nombre: string con el nombre de la persona a crear
 */
void Persona::Print() const {
 std::cout << "Nombre: " << apellido() << ", " << nombre() << ". Edad: " << edad() << std::endl;
}
