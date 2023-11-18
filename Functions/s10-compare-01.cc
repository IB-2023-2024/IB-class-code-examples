#include <iostream>
#include <string>

int compareStrings(const std::string& str1, const std::string& str2) {
  // Compare the two strings character by character
  size_t minLength = std::min(str1.length(), str2.length());  
  for (size_t i = 0; i < minLength; ++i) {
    if (str1[i] < str2[i]) {
      return -1;  // str1 comes before str2
    } else if (str1[i] > str2[i]) {
      return 1;   // str2 comes before str1
    }
  }  
  // If the common prefix is the same, the shorter string comes first
  if (str1.length() < str2.length()) {
    return -1;  // str1 comes before str2
  } else if (str1.length() > str2.length()) {
    return 1;   // str2 comes before str1
  }  
  return 0; // The strings are equal
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <string1> <string2>" << std::endl;
    return 1;
  }
  std::string string1 = argv[1];
  std::string string2 = argv[2];
  int result = compareStrings(string1, string2);
  if (result < 0) {
    std::cout << "The string '" << string1 << "' comes before '" << string2 << "' alphabetically." << std::endl;
  } else if (result > 0) {
    std::cout << "The string '" << string2 << "' comes before '" << string1 << "' alphabetically." << std::endl;
  } else {
    std::cout << "The strings are equal alphabetically." << std::endl;
  }
  return 0;
}
