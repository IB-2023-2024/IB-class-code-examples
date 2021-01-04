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
 private:
  int year_{};
  int month_{};
  int day_{};
 
 public:
  Date(int year = 2000, int month = 1, int day = 1) 
		   : year_{year}, month_{month}, day_{day} {}
  int year() const { return year_; }
  int month() const { return month_; }
  int day() const { return day_; }
	friend std::ostream& operator<<(std::ostream &out, const Date &date);
	friend bool operator== (const Date &d1, const Date &d2);
	friend bool operator> (const Date &d1, const Date &d2);
};

std::string ToString(const Date $date);
 
#endif
