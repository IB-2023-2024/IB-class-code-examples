/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23 Jun 2020
 * @brief Reading lines of text from file
 *        Bind every line to a string
 *        Afterwards parse the string
 *
 * @see https://en.cppreference.com/w/cpp/string/basic_string/getline
 * @see https://en.cppreference.com/w/cpp/string/basic_string/substr
 * @ https://www.cplusplus.com/reference/string/string/find/
 *
 * Note: npos is a static member constant value with the greatest possible value for an element of type size_t.
 * This value, when used as the value for a len (or sublen) parameter in string's member functions, means "until the end of the string".
 *
 * La llamada line.find("filename", 0) busca la subcadena "filename" 
 * a partir de la primera posición (la 0) de la cadena line.
 * Tal como indica la documentación del método find, si la subcadena 
 * no se encuentra, el método retorna el valor string::npos
 * Por lo tanto la sentencia if ejecuta la llamada
 * file_name = line.substr (line.find("=", 0) + 1, string::npos)
 * siempre que en la línea encuentre la subcadena "filename".
 * La llamada anterior captura el nombre del fichero obteniéndolo a 
 * partir del símbolo "=" que figura en la línea donde aparece el nombre del fichero.
 */

#include <fstream>    // For the file streams
#include <iostream>

using namespace std;

int main() {
  string line, file_name;
  const string kInputFilename = "test_bel.txt";
  ifstream input(kInputFilename, ios_base::in);

  // Read data line-wise
  while (getline(input, line)) {
    cout << "Read: " << line << endl;
    // String has a find method
    size_t loc = line.find("filename", 0);
    if (loc != string::npos) {
      file_name = line.substr (line.find("=", 0) + 1, string::npos);
    }
  }
  cout << "Filename found: " << file_name << endl;
  return (0);
}

// Content of the test_bel.txt file
// ===============================
// HEADER
// a = 4.5
// filename = /home/fsande/.bashrc
// ===============================
// 2.34
// 1 2.23
// ER SIE ES
