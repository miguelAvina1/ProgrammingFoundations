#include <iostream>
#include <cmath>

int main () {
    
    int base;
    int exponent;
    

    std::cout << "Please input the base: ";
    std::cin >> base;
    std::cout << "You entered " << base << std::endl;
    std::cout << "Please input the exponent: ";
    std::cin >> exponent;
    std::cout << "You entered " << exponent << std::endl;

    int result = pow(base, exponent);
    std::cout << result << std::endl;


    return 0;
}