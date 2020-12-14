/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 17 Jun 2020
 * @brief Header/Source Separation 
 *
 * This a "header" file containing definitions
 * 
 * #pragma once is a non-standard pragma that is supported by the vast majority of modern compilers. 
 * If it appears in a header file, it indicates that it is only to be parsed once, 
 * even if it is (directly or indirectly) included multiple times in the same source file.
 * 
 * Standard approach to preventing multiple inclusion of the same header is by using include guards:
 *
 * @see https://en.cppreference.com/w/cpp/preprocessor/impl
 */

#pragma once       // Ensure file is included only once
void MakeItSunny();
void MakeItRain();
