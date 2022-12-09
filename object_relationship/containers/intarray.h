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

#include <cassert> // assert()

class IntArray {
 public:
  IntArray() = default;
  IntArray(const int length);
  ~IntArray();
  void Erase();
  int& operator[](const int index);
  void Reallocate(const int newLength);
  void Resize(const int newLength);
  void InsertBefore(const int value, const int index);
  void Remove(const int index);
  // A couple of additional functions just for convenience
  void InsertAtBeginning(const int value);
  void InsertAtEnd(const int value); 
  int length() const;
 private:
  int length_{};
  int *data_{};
};

#endif
