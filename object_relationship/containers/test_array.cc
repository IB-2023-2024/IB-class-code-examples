/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief Example to illustrate container classes
 *        This example uses an integer array class written from scratch 
 * @see https://www.learncpp.com/cpp-tutorial/container-classes/
 */

#include <iostream>
#include "intarray.h"

int main() {
	const int kArraySize = 10;

  // Declare an array with kArraySize elements
  IntArray array(kArraySize);

  // Fill the array with numbers 1 through kArraySize
  for (int i{0}; i < kArraySize; ++i)
    array[i] = i + 1;

  // Resize the array to 8 elements
  array.Resize(8);

  // Insert the number 20 before element with index 5
  array.InsertBefore(20, 5);

  // Remove the element with index 3
  array.Remove(3);

  // Add 30 and 40 to the end and beginning
  array.InsertAtEnd(30);
  array.InsertAtBeginning(40);

  // Print out all the numbers
  for (int i{0}; i < array.length(); ++i)
    std::cout << array[i] << ' ';
  std::cout << '\n';

  return 0;
}
