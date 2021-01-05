/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 05 Jan 2021
 * @brief A simple game using the Creature and Point2D classes
 *        Many games and simulations have creatures or objects 
 *        that move around a board, map, or screen. 
 *        One thing that all of these creatures/objects have in common 
 *        is that they all have a location. 
 *        This example, uses a Creature class that uses a point class 
 *        to hold the creature’s location.
 *
 * @see https://www.learncpp.com/cpp-tutorial/composition/
 */

#include <string>
#include <iostream>

#include "creature.h"
#include "point2D.h"
 
int main() {
  std::cout << "Enter a name for your creature: ";
  std::string name;
  std::cin >> name;
  Creature creature{name, {4, 7}};
	
  while (true) {
    // print the creature's name and location
    std::cout << creature << '\n';
 
    std::cout << "Enter new X location for creature (-1 to quit): ";
    int x{0};
    std::cin >> x;
    if (x == -1)
      break;
 
    std::cout << "Enter new Y location for creature (-1 to quit): ";
    int y{0};
    std::cin >> y;
    if (y == -1)
      break;
		
    creature.moveTo(x, y);
  }
  return 0;
}
