// A C++ program to show difference 
// between exit() and _Exit() 
//
// https://www.geeksforgeeks.org/exit-vs-_exit-c-cpp/

#include<bits/stdc++.h> 

using namespace std; 
  
void fun(void) { 
   cout << "Exiting"; 
} 
  
int main() { 
   atexit(fun); 
   exit(10); 
} 

