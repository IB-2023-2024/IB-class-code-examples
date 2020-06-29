/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F.de Sande
 * @date 25 Jun 2020
 * @brief Class Example
 *
 * @see http://www.cplusplus.com/doc/tutorial/classes/
 */

class MyClass {
  public:
    int SetValue (int newValue ) {		// member function
      int oldValue = value;// save old value
      value = newValue;// change value to new value
      return oldValue;// return old value
  }
  private:
  friend void WasteTime ();
  void DoNothing () {}
  int value;							// data member
};

void WasteTime () {
  MyClass x;
  x.DoNothing ();					// OK: friend
  x.value = 5; 						//OK: friend
}
void func () {
  MyClass x;							// x is object of type MyClass
  x.SetValue (5);					// call MyClass’s SetValue member
  												// (sets x.value to 5)
  x.value = 5;						// ERROR: value is private
  x.DoNothing ();				// ERROR: doNothing is private
}

int main() {
  Func();
	return 0;
}
