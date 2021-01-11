#include "reverse_string.h"

namespace reverse_string {
  std::string reverse_string(const std::string& my_string) {
    std::string result{""};
    const unsigned kLength = my_string.length();

    for (unsigned i = 0; i < kLength; ++i) {
      result += my_string[kLength - i - 1]; 
    }
    return result;
  }
}  // namespace reverse_string
