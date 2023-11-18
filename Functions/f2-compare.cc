#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    std::cerr << "Usage: " << argv[0] << " <file1> <file2>" << std::endl;
    return 1;
  }
  std::string file1 = argv[1];
  std::string file2 = argv[2];
  std::ifstream input1(file1);
  std::ifstream input2(file2);
  if (!input1.is_open() || !input2.is_open()) {
    std::cerr << "Failed to open one or both files." << std::endl;
    return 2;
  }
  std::string line1;
  std::string line2;
  int lineNumber = 1;
  bool areFilesEqual = true;
  while (std::getline(input1, line1) && std::getline(input2, line2)) {
    if (line1 != line2) {
      std::cout << "Files differ at line " << lineNumber << ":" << std::endl;
      std::cout << file1 << ": " << line1 << std::endl;
      std::cout << file2 << ": " << line2 << std::endl;
      areFilesEqual = false;
      break;
    }
    lineNumber++;
  }
  if (areFilesEqual) {
    std::cout << "Files are equal." << std::endl;
  }
  input1.close();
  input2.close();
  return 0;
}
