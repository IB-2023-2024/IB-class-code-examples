/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 13 Nov 2020
 * @brief show difference between exit() and _Exit() 
 *        exit() aborts the execution of a program
 *
 * @see https://www.geeksforgeeks.org/exit-vs-_exit-c-cpp/
 * 
 */

#include<bits/stdc++.h> 

void fun(void) { 
  std::cout << "Exiting"; 
} 
  
int main() { 
  atexit(fun); 
  exit(10); 
} 
