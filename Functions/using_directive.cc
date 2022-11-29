/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author F. de Sande
 * @date Dec 3 2020
 * Updated Nov 29 2022 
 * @brief The using directive
 *        A using directive tells the compiler to check a specified 
 *        namespace when trying to resolve an identifier that has no namespace prefix. 
 *        Many texts, tutorials, and even some compilers recommend or use a using 
 *        directive at the top of the program. 
 *
 *        However, used in this way, this is a bad practice, and highly discouraged.
 *
 *        This code doesn’t compile, because the compiler now can’t tell whether we 
 *        want the cout function that we defined, or the cout that is defined 
 *        inside the std namespace.
 *        When using a using directive in this manner, any identifier we define may conflict 
 *        with any identically named identifier in the std namespace. 
 *        Even worse, while an identifier name may not conflict today, it may conflict with 
 *        new identifiers added to the std namespace in future language revisions. 
 *        This was the whole point of moving all of the identifiers in the standard 
 *        library into the std namespace in the first place!
 *
 *        Warning !!!
 *        Avoid using directives (such as using namespace std;) at the top of your program. 
 *        They violate the reason why namespaces were added in the first place.
 *
 * @see https://www.learncpp.com/cpp-tutorial/2-9-naming-collisions-and-an-introduction-to-namespaces/
 * @see https://isocpp.org/wiki/faq/coding-standards#using-namespace-std
 */

#include <iostream> // imports the declaration of std::cout

using namespace std; // makes std::cout accessible as "cout"

int cout() { // declares our own "cout" function
  return 5;
}

int main() {
  cout << "Hello, world!"; // Compile error!  Which cout do we want here?  The one in the std namespace or the one we defined above?
  return 0;
}
