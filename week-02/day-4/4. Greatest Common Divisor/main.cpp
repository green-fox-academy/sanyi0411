#include <iostream>

int greatestCommonDivisor_Recursively(int a, int b);
int greatestCommonDivisor_Recursively2(int a, int b);

int main() {

    //Find the greatest common divisor of two numbers using recursion.
    int a = 121;
    int b = 33;
    std::cout << greatestCommonDivisor_Recursively(121, 33) << std::endl;
    std::cout << greatestCommonDivisor_Recursively2(121, 33) << std::endl;
    std::cout << b % a;

    return 0;
}

int greatestCommonDivisor_Recursively(int a, int b) {
    if (a == 0)
        return b;
    return greatestCommonDivisor_Recursively(b % a, a);
}

int greatestCommonDivisor_Recursively2(int a, int b) {
    if (b == 0) {
        return a;
    }
    return greatestCommonDivisor_Recursively2(b, a % b);
}
