#include <iostream>

int main(int argc, char* args[]) {

    // Create a program that prints a few operations on two numbers: 22 and 13
    int a = 22;
    int b = 13;
    double c = (double)a/(double)b;

    // Print the result of 13 added to 22
    std::cout << a+b << std::endl; //outputs 35

    // Print the result of 13 substracted from 22
    std::cout << b-a << std::endl; //outputs -9

    // Print the result of 22 multiplied by 13
    std::cout << a*b << std::endl; //outputs 286

    // Print the result of 22 divided by 13 (as a decimal fraction)
    std::cout << c << std::endl; //outputs 1.6923

    // Print the integer part of 22 divided by 13
    std::cout << a/b << std::endl; //outputs 1

    // Print the reminder of 22 divided by 13
    std::cout << a%b << std::endl; //outputs 9

    return 0;
}