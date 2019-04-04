#include <iostream>

int main(int argc, char *args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // square like this:
    //
    //
    // %%%%%
    // %%  %
    // % % %
    // %  %%
    // %%%%%
    //
    // The square should have as many lines as the number was

    int a;
    std::cout << "Enter the size of the diagonal: \n";
    std::cin >> a;

    for (int i = 0; i < a; i++) {
        std::cout << "%";
    }
    std::cout << std::endl;

    for (int i = 2; i < a; i++) {
        std::cout << "%";
        for (int j = 0; j < a - 2; j++) {
            if (j == i - 2) {
                std::cout << "%";
            } else {
                std::cout << " ";
            }
        }
        std::cout << "%" << std::endl;
    }

    for (int i = 0; i < a; i++) {
        std::cout << "%";
    }
    std::cout << std::endl;

    return 0;
}