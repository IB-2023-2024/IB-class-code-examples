/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief Date class Definition
 *        Header guards:
 *        When this header is #included, the preprocessor checks whether DATE_H 
 *        has been previously defined. 
 *        If this is the first time we’re including the header, DATE_H will not have been defined. 
 *        Consequently, it #defines DATE_H and includes the contents of the file. 
 *        If the header is included again into the same file, DATE_H will already have been defined 
 *        from the first time the contents of the header were included, and the contents of the header 
 *        will be ignored (thanks to the #ifndef).
 *
 * @see https://www.learncpp.com/cpp-tutorial/89-class-code-and-header-files/
 * @see https://www.learncpp.com/cpp-tutorial/header-guards/
 */

#ifndef DATE_H
#define DATE_H
 
class Date {
 public:
  Date() = default;  /// Tell the compiler to create a default constructor
  Date(int year, int month, int day);
  void Print();
  void SetDate(int year, int month, int day);
  int getYear() { return year_; }
  int getMonth() { return month_; }
  int getDay()  { return day_; }
 private:
  int year_;
  int month_;
  int day_;
};
 
#endif
