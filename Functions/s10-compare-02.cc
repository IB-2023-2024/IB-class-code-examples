#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <string1> <string2>" << std::endl;
    return 1;
  }
  std::string string1 = argv[1];
  std::string string2 = argv[2];
  // Comparar las cadenas
  int result = string1.compare(string2);
  if (result < 0) {
    std::cout << "The string '" << string1 << "' comes before '" << string2 << "' alphabetically." << std::endl;
  } else if (result > 0) {
    std::cout << "The string '" << string2 << "' comes before '" << string1 << "' alphabetically." << std::endl;
  } else {
    std::cout << "The strings are equal alphabetically." << std::endl;
  }
  return 0;
}
