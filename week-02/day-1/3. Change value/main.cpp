#include <iostream>

int main() {
    // Change the value of the variable called 'temperature' using a pointer
    // (you have to create the pointer first)

    float temperature = 21.3;
    float *tempPtr = &temperature;

    *tempPtr = 25.2;

    std::cout << "The temperature after changing is: " << *tempPtr << std::endl;

    return 0;
}