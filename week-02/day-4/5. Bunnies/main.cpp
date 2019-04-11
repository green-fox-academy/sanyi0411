#include <iostream>

int bunnies (int number);
int bunnies2 (int number2);

int main() {

    //We have a number of bunnies and each bunny has two big floppy ears.
    //We want to compute the total number of ears across all the bunnies recursively (without loops or multiplication).

    std::cout << bunnies(6) << std::endl;
    std::cout << bunnies2(6) << std::endl;

    return 0;
}

int bunnies (int number) {
    if (number > 1) {
        return 2 + bunnies (number - 1);
    } else {
        return 2;
    }
}

int bunnies2 (int number2) {
    if (number2 == 1) {
        return 2;
    }
    return 2 + bunnies2(number2 - 1);
}