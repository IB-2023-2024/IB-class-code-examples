/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23.nov.2020
 * @brief Definitions for palindrome numbers
 */

void Usage(int argc, char *argv[]);
bool IsPalindrome(int numero);
void MinMaxPalindrome(const size_t lower, const size_t upper);

const std::string kHelpText = "Este programa, dado un rango de números [m, N] dados por el usuario en \
															 línea de comandos, calcula todos los productos de números dentro de ese \
															 intervalo que son palíndromos";
