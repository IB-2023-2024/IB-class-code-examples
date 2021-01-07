/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief IntArray class declaration
 * @see https://www.learncpp.com/cpp-tutorial/container-classes/
 */

#ifndef INT_ARRAY_H
#define INT_ARRAY_H

#include <cassert> // for assert()

class IntArray {
 public:
  IntArray() = default;
  IntArray(int length);
  ~IntArray();
  void erase();
  int& operator[](int index);
  void reallocate(int newLength);
  void resize(int newLength);
  void insertBefore(int value, int index);
  void remove(int index);
  // A couple of additional functions just for convenience
  void insertAtBeginning(int value);
  void insertAtEnd(int value); 
  int getLength() const;
 private:
  int length_{};
  int *data_{};
};

#endif
