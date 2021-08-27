#include <iostream>

using std::cout;

int main () {

    int slices;
    slices = 5 + 1;

    int children = slices;
    slices = 10000;
    auto mys = " Children";

    cout << "You have " << children << mys << std::endl;

    printf("%i\n", slices);

    cout << "Int size: " << sizeof(int) << std::endl;
    cout << "uint8_t size: " << sizeof(uint8_t) << std::endl;
    cout << "uint16_t size: " << sizeof(uint16_t) << std::endl;
    cout << "float size: " << sizeof(float) << std::endl;
    cout << "double size: " << sizeof(double) << std::endl;
    cout << "char size: " << sizeof(char) << std::endl;
    cout << "long long size: " << sizeof(long long) << std::endl;
    cout << "short size: " << sizeof(short) << std::endl;

}