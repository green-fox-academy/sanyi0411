#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stored number is lower
    // You found the number: 8

    int a = 5; //The user has to guess this number
    int g;
    bool b = false;
    do {
        std::cout << "Guess a number!\n";
        std::cin >> g;
        if (a == g) {
            b = true;
        } else if (a < g) {
            std::cout << "The stored number is lower\n";
        } else {
            std::cout << "The stored number is higher\n";
        }
    } while (b == false);
    std::cout << "You found the number " << a << std::endl;

return 0;
}