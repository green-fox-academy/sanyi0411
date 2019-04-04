#include <iostream>

int main(int argc, char* args[]) {

    // Create a program that asks for a number and prints the multiplication table with that number
    //
    // Example:
    // The number 15 should print:
    //
    // 1 * 15 = 15
    // 2 * 15 = 30
    // 3 * 15 = 45
    // 4 * 15 = 60
    // 5 * 15 = 75
    // 6 * 15 = 90
    // 7 * 15 = 105
    // 8 * 15 = 120
    // 9 * 15 = 135
    // 10 * 15 = 150

    int a;
    std::cout << "Please enter a number\n";
    std::cin >> a;

    for (int i = 0; i < 10; i++) {
        std::cout << i + 1 << " * " << a << " = " << (i + 1) * a << std::endl;
    }

return 0;
}