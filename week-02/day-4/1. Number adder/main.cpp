#include <iostream>

int adder (int n) {
    if (n == 1) {
        return 1;
    } else {
        int sum = n + adder(n - 1);
    }
}

int main() {

    //Write a recursive function that takes one parameter: n and adds numbers from 1 to n.

    std::cout << adder(6) << std::endl;

    return 0;
}