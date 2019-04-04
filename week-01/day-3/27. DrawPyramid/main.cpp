#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // pyramid like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //
    // The pyramid should have as many lines as the number was
    int a;

    std::cout <<"Please enter how many rows the pyramid should have: \n";
    std::cin >> a;

    for(int i = 1, k = 0; i <= a; ++i, k = 0) {
        for(int b = 1; b <= a-i; b++)
        {
            std::cout <<"  ";
        }

        while(k != 2*i-1)
        {
            std::cout << "* ";
            ++k;
        }
        std::cout << std::endl;
    }

    return 0;
}