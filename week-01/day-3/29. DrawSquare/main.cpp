#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%%
    // %    %
    // %    %
    // %    %
    // %    %
    // %%%%%%
    //
    // The square should have as many lines as the number was

    int a;
    std::cout << "Enter the size of the square: \n";
    std::cin >> a;

    for (int i = 0; i < a; i++) {
        std::cout << "%";
    }
    std::cout << std::endl;

    for (int i = 2; i < a; i++) {
        std::cout << "%";
        for (int j = 2; j < a; j++) {
            std::cout << " ";
        }
        std::cout << "%" << std::endl;
    }

    for (int i = 0; i < a; i++) {
        std::cout << "%";
    }
    std::cout << std::endl;

    return 0;
}