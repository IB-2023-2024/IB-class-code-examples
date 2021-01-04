
/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 09 Nov 2020
 * @brief A simple class for Matrix
 * 
 * @see http://www.parashift.com/c++-faq-lite/matrix-subscript-op.html
 * @see https://isocpp.org/wiki/faq/operator-overloading#matrix-subscript-op
 */

#include <iostream>
#include <cassert>

class Matrix {
public:
  Matrix(unsigned rows, unsigned cols);
  double& operator() (unsigned row, unsigned col);        // Subscript operators often come in pairs
  double  operator() (unsigned row, unsigned col) const;  // Subscript operators often come in pairs
  // ...
 ~Matrix();                              // Destructor
  Matrix(const Matrix& m);               // Copy constructor
  Matrix& operator= (const Matrix& m);   // Assignment operator
  // ...
private:
  unsigned rows_, cols_;
  double* data_;
};

inline
Matrix::Matrix(unsigned rows, unsigned cols)
  : rows_ (rows)
  , cols_ (cols)
//, data_ ← initialized below after the if...throw statement
{
  assert(((rows != 0) && (cols != 0)) && "Matrix constructor has 0 size");
  data_ = new double[rows * cols];
}

  inline
Matrix::~Matrix()
{
  delete[] data_;
}

inline
double& Matrix::operator() (unsigned row, unsigned col) {
  assert((row < rows_ && col < cols_) && "Matrix subscript out of bounds");
  return data_[cols_*row + col];
}

inline
double Matrix::operator() (unsigned row, unsigned col) const {
  assert((row < rows_ && col < cols_) && "const Matrix subscript out of bounds");
  return data_[cols_*row + col];
}

int main() {
  Matrix m(10, 10);
  m(5, 8) = 106.15;
  std::cout << m(5,8);
  // ...
}
