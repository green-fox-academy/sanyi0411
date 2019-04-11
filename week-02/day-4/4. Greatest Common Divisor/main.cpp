#include <iostream>

int lnko_Recursively (int a, int b);

int main() {

    //Find the greatest common divisor of two numbers using recursion.

    std::cout << lnko_Recursively (121, 33) << std::endl;

    return 0;
}

int lnko_Recursively (int a, int b) {
    if (a == 0)
        return b;
    return lnko_Recursively(b % a, a);
}
