/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date Nov 9 2023
 * @brief A class with defined destructor
 *
 * When object reaches end of lifetime, typically some cleanup required before object passes out of existence
 * Destructor is member function that is automatically called when object reaches end of lifetime in order to perform any necessary cleanup
 * Often object may have allocated resources associated with it (e.g., memory, files, devices, network connections, processes/threads)
 * When object destroyed, must ensure that any resources associated with object are released
 * Destructors often serve to release resources associated with object
 * Destructor for class T always has name T:: ̃T
 * Destructor has no return type (not even void)
 * Destructor cannot be overloaded
 * Destructor always takes no parameters
 * If no destructor is specified, destructor automatically provided that calls destructor for each data member of class type
 * Sometimes, automatically provided destructor will not have correct behavior
 *
 * In this example, if sendData() method is not called (for any reason) data would be lost
 * 
 * @see https://www.learncpp.com/cpp-tutorial/introduction-to-destructors/
 */

#include <iostream>
#include <string>
#include <vector>

class NetworkData {
 public:
	NetworkData(std::string_view serverName) : serverName_ { serverName } { }
	void addData(const std::string& data) {
		data_.push_back(data);
	}
	void sendData() {
		// connect to server
		// send all data
		// clear data
	}
 private:
  std::string serverName_{};
  std::vector<std::string> data_{};
};

bool someFunction() {
  NetworkData network("someipAddress");
  network.addData("somedata1");
  network.addData("somedata2");
  if (true) {
    return false;
  }
  network.sendData();
  return true;
}

int main() {
  NetworkData network("someipAddress");
  network.addData("somedata1");
  network.addData("somedata2");
  network.sendData();
  return 0;
}
