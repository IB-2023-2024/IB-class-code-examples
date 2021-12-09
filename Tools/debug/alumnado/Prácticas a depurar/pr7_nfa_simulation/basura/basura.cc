#include <iostream>
#include <map>
#include <vector>
#include <math.h>

using namespace std;

std::vector<int> give_me_second (std::string s,map<std::string,std::vector<int>>& first) {
  return(first[s]);
}

int main (){
  // std::string s {"180"};
  // int hola = 0;
  // std::string s_reversed;
  // for (int i {s.length()}; i >= 0; i--) {
  //   s_reversed += s[i];
  // }
  // std::cout << s_reversed << std::endl;

  // for (int i {1}; i < s_reversed.length(); i++) {
  //   hola += (s_reversed[i] -'0') * (pow(10,i-1));
  //   std::cout <<"---"<< s_reversed[i] -'0' <<"---" << std::endl;
  // }
  // std::cout << hola << std::endl;
  // bool pdt = false;
  // while (pdt == false) {
  //   for (int i{0}; i < 8; i++) {
  //     if (i%2 == 0) {
  //       pdt = true;
  //     }
  //     std::cout << i << " " << pdt << std::endl;
  //   }
  // }
  // map<std::string,std::vector<int>> first;
  // std::vector<int> v{0,1,2,3,4,5};

  // //initializing
  // first["a"]=v;
  // first["c"]=v;
  
  // //  map<std::string, int>::iterator it;
  // //  for(it=first.begin(); it!=first.end(); ++it){
  // //     cout << it->first << " => " << it->second << '\n';
  // //  }

  // //  std::cout << first["a"] << std::endl;
  // for (int i{0}; i < give_me_second("a",first).size(); i++ ){
  //   std::cout << give_me_second("a",first)[i] << " ";
  // }
  // std::cout << std::endl;
  bool pedro = false;
  while ( pedro != true) {
    int input{0};
    std::cin >> input;
    if (input == 1) {
      pedro = true;
    }
  }

  return 0;
}
// 6
// 0
// 0 0 4 a 2 cbd 1 & 5 & 3 & 1
// 1 0 1 ag 3
// 2 0 1 b 4
// 3 0 1 a 0
// 4 0 1 b 5
// 5 1 0

// 6
// 0
// 0 0 4 a 2 b 1 & 5 & 3
// 1 0 1 a 3
// 2 0 1 b 4
// 3 0 1 a 0
// 4 0 1 b 5 b 0
// 5 1 0

// abbabb
// a
// bb
// abb
// bab
// bbbb
// ababaa
// cbdacbd
// &
