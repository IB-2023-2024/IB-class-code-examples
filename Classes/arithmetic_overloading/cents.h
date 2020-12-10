/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 10 Dec 2020
 * @brief Declaration of the Cent class
 */

class Cents {
 private:
  int cents_{};

 public:
  Cents(int cents) : cents_{ cents } 
	{}

  int GetCents() const { return cents_; }
};

// Need to explicitly provide prototype for operator+ so uses of operator+ in other files know this overload exists
Cents operator+(const Cents &c1, const Cents &c2);
