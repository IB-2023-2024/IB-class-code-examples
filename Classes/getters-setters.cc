/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 25 Jun 2020
 * @brief Date class Example with getters and setters
 *        The Date class is essentially an encapsulated data struct with a trivial implementation, 
 *        and a user of the class might reasonably expect to be able to get or set the day, month, or year.
 *
 * @see https://www.learncpp.com/cpp-tutorial/84-access-functions-and-encapsulation/
 */
#include <iostream>
 
class DateClass {
 private:
  int year_{};  // Initialize to 0
  int month_{};
  int day_{};
 
 public:
  void print() {
    std::cout << year_ << '/' << month_ << '/' << day_;
  }
  int getMonth() { return month_; } // getter for month
  void setMonth(int month) { month_ = month; } // setter for month
 
  int getDay() { return day_; } // getter for day
  void setDay(int day) { day_ = day; } // setter for day
 
  int getYear() { return year_; } // getter for year
  void setYear(int year) { year_ = year; } // setter for year
};
 
int main() {
  DateClass today;
	today.setDay(3);
	today.setMonth(12);
	today.setYear(2020);
  today.print(); 
  return 0;
}
