#include <iostream>

int powerRecursively (int base, int power);

int main() {

    //Given base and n that are both 1 or more, compute recursively (no loops) the value of base to the n power,
    // so powerN(3, 2) is 9 (3 squared).

    std::cout << powerRecursively (2, 8) << std::endl;

    return 0;
}

int powerRecursively (int base, int power) {
    int sum = 1;
    if (power > 1) {
        sum = base * powerRecursively(base, power - 1);
    } else {
        return base;
    }
    return sum;
}