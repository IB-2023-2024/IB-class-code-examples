/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 10 Dec 2020
 * @brief Friend functions 
 *        Normally, only class has access to its private members
 *        Sometimes, necessary to allow another class or function to have access to private members of class
 *        Friend of class is function/class that is allowed to access private members of class
 *        To make function or class friend of another class, use friend statement
 *        A function can be a friend of more than one class at the same time
 *
 *        In this code PrintWeather is a friend of both Humidity and Temperature.
 *
 *        Being a friend function, printWeather can access private members in Temperature and Humidity classes
 *
 * @see https://www.learncpp.com/cpp-tutorial/813-friend-functions-and-classes/
 */

#include <iostream>

/// This (class Humidity) is a class prototype that tells the compiler 
//  that we are going to define a class called Humidity in the future. 
//
/// Without this line, the compiler would tell us it doesn’t know what a Humidity is when parsing the prototype 
/// for PrintWeather() inside the Temperature class. 
class Humidity;

class Temperature {
 public:
  Temperature(int temp = 0) { temp_ = temp; }
  friend void PrintWeather(const Temperature &temperature, const Humidity &humidity);
 private:
  int temp_;
};

class Humidity {
 public:
  Humidity(int humidity=0) { humidity_ = humidity; }
  friend void PrintWeather(const Temperature &temperature, const Humidity &humidity);
 private:
  int humidity_;
};

void PrintWeather(const Temperature &temperature, const Humidity &humidity) {
  std::cout << "The temperature is " << temperature.temp_ <<
               " and the humidity is " << humidity.humidity_ << '\n';
}

int main() {
  Humidity hum(10);
  Temperature temp(12);
  PrintWeather(temp, hum);

  return 0;
}
