/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief IntArray class definition
 *        In this example, we implement an integer array class from scratch 
 *        that implements most of the common functionality that containers should have. 
 *        The array class is going to be a value container, which will hold copies of 
 *        the elements it’s organizing. 
 *        As the name suggests, the container will hold an array of integers, similar to std::vector<int>.
 * @see https://www.learncpp.com/cpp-tutorial/container-classes/
 */

#include "intarray.h"

/**
 * Constructor
 * @param length Number of elements in the array
 */
IntArray::IntArray(int length): length_{ length } {
  assert(length >= 0);
  if (length > 0)
    data_ = new int[length]{};
}

/**
 * Destructor
 */
IntArray::~IntArray() {
  delete[] data_;
  // we don't need to set data_ to null or length_ to 0 here, since the object will be destroyed immediately after this function anyway
}

/**
 *  Erases the array and set the length to 0.
 */
void IntArray::erase() {
  delete[] data_;
  // We need to make sure we set data_ to nullptr here, otherwise it will
  // be left pointing at deallocated memory!
  data_ = nullptr;
  length_ = 0;
}

/**
 * Returns an array element
 * @param index. Index of the element to return
 * @return the array element at index
 */
int& IntArray::operator[](int index) {
  assert(index >= 0 && index < length_);
  return data_[index];
}

/**
 * Resizes the array.  
 * Any existing elements will be destroyed.  
 * This function operates quickly.
 * @param newLength. New size of the array
 */
void IntArray::reallocate(int newLength) {
  // First we delete any existing elements
  erase();

  // If our array is going to be empty now, return here
  if (newLength <= 0)
    return;

  // Then we have to allocate new elements
  data_ = new int[newLength];
  length_ = newLength;
}

/**
 * Resizes the array.  
 * Any existing elements will be kept.  
 * This function operates slowly.
 * @param newLength. New size of the array
 */
void IntArray::resize(int newLength) {
  // if the array is already the right length, we're done
  if (newLength == length_)
    return;

  // If we are resizing to an empty array, do that and return
  if (newLength <= 0) {
    erase();
    return;
  }

  // Now we can assume newLength is at least 1 element.  This algorithm
  // works as follows: First we are going to allocate a new array.  Then we
  // are going to copy elements from the existing array to the new array.
  // Once that is done, we can destroy the old array, and make data_
  // point to the new array.

  // First we have to allocate a new array
  int *data{ new int[newLength] };

  // Then we have to figure out how many elements to copy from the existing
  // array to the new array.  We want to copy as many elements as there are
  // in the smaller of the two arrays.
  if (length_ > 0) {
    int elementsToCopy{ (newLength > length_) ? length_ : newLength };

    // Now copy the elements one by one
    for (int index{ 0 }; index < elementsToCopy ; ++index)
      data[index] = data_[index];
  }

  // Now we can delete the old array because we don't need it any more
  delete[] data_;

  // And use the new array instead!  Note that this simply makes data_ point
  // to the same address as the new array we dynamically allocated.  Because
  // data was dynamically allocated, it won't be destroyed when it goes out of scope.
  data_ = data;
  length_ = newLength;
}

/**
 * Inserts a value before a given position in the array
 * @param value Value to insert
 * @param index. The value is inserted just before this index
 */
void IntArray::insertBefore(int value, int index) {
  // Sanity check our index value
  assert(index >= 0 && index <= length_);

  // First create a new array one element larger than the old array
  int *data{ new int[length_ + 1] };

  // Copy all of the elements up to the index
  for (int before{0}; before < index; ++before)
    data[before] = data_[before];

  // Insert our new element into the new array
  data[index] = value;

  // Copy all of the values after the inserted element
  for (int after{ index }; after < length_; ++after)
    data[after + 1] = data_[after];

  // Finally, delete the old array, and use the new array instead
  delete[] data_;
  data_ = data;
  ++length_;
}

/**
 * 
 * @param index. Index of the element to remove
 */
void IntArray::remove(int index) {
  // Sanity check our index value
  assert(index >= 0 && index < length_);

  // If we're removing the last element in the array, we can just erase the array and return early
  if (length_ == 1) {
    erase();
    return;
  }

  // First create a new array one element smaller than the old array
  int *data{ new int[length_ - 1] };

  // Copy all of the elements up to the index
  for (int before{ 0 }; before  < index; ++before)
    data[before] = data_[before];

  // Copy all of the values after the removed element
  for (int after{ index + 1 }; after < length_; ++after)
    data[after - 1] = data_[after];

  // Finally, delete the old array, and use the new array instead
  delete[] data_;
  data_ = data;
  --length_;
}

/**
 * Inserts a value at the first position of the array 
 * @param value to insert
 */
void IntArray::insertAtBeginning(int value) { 
  insertBefore(value, 0); 
}

/**
 * Inserts a value at the last position of the array
 * @param value to insert
 */
void IntArray::insertAtEnd(int value) { insertBefore(value, length_); }

/**
 * Getter
 * @return the number of elements in the array
 */
int IntArray::getLength() const { 
  return length_; 
}
