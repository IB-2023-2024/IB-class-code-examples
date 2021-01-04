/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief Encapsulated classes help protect your data and prevent misuse
 *        If users can access the array directly, they could subscript the array with 
 *        an invalid index, producing unexpected results
 *
 * @see https://www.learncpp.com/cpp-tutorial/84-access-functions-and-encapsulation/
 */

class IntArray {
 public:
  int store_[10];
};

int main() {
  IntArray my_array;
  my_array.store_[16] = 2; /// invalid array index, now we overwrote memory that we don't own
}
