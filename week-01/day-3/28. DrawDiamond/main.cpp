#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that reads a number from the standard input, then draws a
    // diamond like this:
    //
    //
    //    *
    //   ***
    //  *****
    // *******
    //  *****
    //   ***
    //    *
    //
    // The diamond should have as many lines as the number was

    int z, a;

    std::cout <<"Please enter how many rows the diamond should have: \n";
    std::cin >> z;

    if (z % 2 == 0) {
        a = z / 2;
    } else {
        a = (z / 2) + 1;
    }

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
    for (int i = a - 1, k =0; i > 0; i--, k = 0) {
        for(int b = 1; b <= a-i; b++)
        {
            std::cout <<"  ";
        }

        while(k != 2*i-1)
        {
            std::cout << "* ";
            k++;
        }
        std::cout << std::endl;
    }

return 0;
}