#include <iostream>
 
int main() {
    int a {10};
    int b {0};
    std::cout << a << " / " << b << " = " << a / b; // division by 0 is undefined
    return 0;
}
