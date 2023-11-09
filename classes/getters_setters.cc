/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Jun 25 2020
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
  int GetDay() { return day_; }      // getter for day
  int GetMonth() { return month_; }  // getter for month
  int GetYear() { return year_; }    // getter for year
  void SetDay(const int day) { day_ = day; }         // setter for day
  void SetMonth(const int month) { month_ = month; } // setter for month
  void SetYear(const int year) { year_ = year; }     // setter for year
 private:
  int year_{};  // Initialize to 0
  int month_{};
  int day_{};
};
 
int main() {
  DateClass today;
  today.SetDay(10);
  today.SetMonth(11);
  today.SetYear(2023);
  today.Print(); 
  return 0;
}
