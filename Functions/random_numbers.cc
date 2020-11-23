/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 23.nov.2020
 * @brief Ilustrar la generación de números pseudo-aleatorios usando rand()
 *        Ejecute este programa varias veces y observe los números "aleatorios" que
 *        se generan.
 *        El programa utiliza la función time() 
 *        Lea la información que se presenta en el siguiente enlace:
 * @see https://www.geeksforgeeks.org/rand-and-srand-in-ccpp/
 * @see https://www.programiz.com/cpp-programming/library-function/ctime/time#:~:text=The%20time()%20function%20takes,object%20pointed%20to%20by%20arg%20.
 */

#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;

int main() {
	cout << "The rand function delivers pseudo-random numbers in the range of 0 to RAND_MAX: " << RAND_MAX << endl;
  
	int random = rand();
	/* No srand() calls before rand(), so seed = 1*/
	cout << "Seed = 1, Random number1 = " << random << endl;
	random = rand();
	cout << "Seed = 1, Random number2 = " << random << endl;

	srand(5);
	/* Seed = 5 */
	random = rand();
	cout << "Seed = 5, Random number3 = " << random << endl;
	random = rand();
	cout << "Seed = 5, Random number4 = " << random << endl;
	
	srand(time(NULL));
	/* Now seed depends on time */
	// Use current time as seed for random generator 

	const int kLimit = 10;
  for(int i = 0; i < kLimit; i++) {
	  random = rand();
	  cout << "Random number: = " << random << endl;
	}

	return 0;
}
