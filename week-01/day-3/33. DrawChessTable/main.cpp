#include <iostream>

int main(int argc, char *args[]) {

    // Create a program that draws a chess table like this
    //
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %
    // % % % %
    //  % % % %

    int a;
    std::cout << "Enter the number of rows of the chess table\n";
    std::cin >> a;

    for (int i = 1; i <= a; i++) {
        if (i % 2 == 0) {
            for (int j = 1; j <= 8; j++) {
                if (j % 2 == 0) {
                    std::cout << " ";
                } else {
                    std::cout << "%";
                }
            }
        } else {
                for (int j = 1; j <= 8; j++) {
                    if (j % 2 == 0) {
                        std::cout << "%";
                    }
                    else {
                        std::cout << " ";
                    }
                }
        }
        std::cout << std::endl;

    }
    return 0;
}