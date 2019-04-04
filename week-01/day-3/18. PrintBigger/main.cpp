#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that asks for two numbers and prints the bigger one

    int a;
    int b;

    std::cout << "Enter two numbers and the program tell you which one is greater.\n";
    std::cout << "The first number: \n";
    std::cin >> a;
    std::cout << "The second number: \n";
    std::cin >> b;

    if (a > b) {
        std::cout << a << " is greater.";
    } else {
        std::cout << b << " is greater.";
    }

    return 0;
}