/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date 19 nov 2020
 * @brief Sample code to illustrate debugging
 *
 * @see https://docs.microsoft.com/en-us/visualstudio/debugger/getting-started-with-the-debugger-cpp?view=vs-2019
 */

#include <string>
#include <vector>
#include <iostream>

void SendMessage(const std::wstring& name, int msg) {
  std::wcout << L"Hello, " << name << L"! Count to " << msg << std::endl;
}

int main() {
  std::vector<wchar_t> letters = { L'f', L'r', L'e', L'd', L' ', L's', L'm', L'i', L't', L'h' };
  std::wstring name = L"";
  std::vector<int> a(10);
  std::wstring key = L"";

  for (int i = 0; i < letters.size(); i++) {
    name += letters[i];
    a[i] = i + 1;
    SendMessage(name, a[i]);
  }
  std::wcin >> key;
  return 0;
}
