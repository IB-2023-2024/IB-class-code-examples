#include <iostream>

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <year>" << std::endl;
    return 1;
  }
  int year = std::stoi(argv[1]);
  if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
    std::cout << year << " is a leap year." << std::endl;
  } else {
    std::cout << year << " is not a leap year." << std::endl;
  }
  return 0;
}
