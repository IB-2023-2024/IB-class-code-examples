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
 public:
  void Print() {
    std::cout << day_ << '/' << month_ << '/' << year_ << std::endl;
  }
  int GetMonth() { return month_; } // getter for month
  void SetMonth(int month) { month_ = month; } // setter for month
 
  int GetDay() { return day_; } // getter for day
  void SetDay(int day) { day_ = day; } // setter for day
 
  int GetYear() { return year_; } // getter for year
  void SetYear(int year) { year_ = year; } // setter for year
 private:
  int year_{};  // Initialize to 0
  int month_{};
  int day_{};
};
 
int main() {
  DateClass today;
  today.SetDay(10);
  today.SetMonth(12);
  today.SetYear(2020);
  today.Print(); 
  return 0;
}
