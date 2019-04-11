#include <iostream>

int bunnies(int n);

int main() {

    //We have bunnies standing in a line, numbered 1, 2, ...
    // The odd bunnies (1, 3, ..) have the normal 2 ears.
    // The even bunnies (2, 4, ..) we'll say have 3 ears, because they each have a raised foot.
    // Recursively return the number of "ears" in the bunny line 1, 2, ... n (without loops or multiplication).

    std::cout << bunnies (6) << std::endl;

    return 0;
}

int bunnies (int n) {
    if (n > 0) {
        if (n % 2 == 0) {
            return 3 + bunnies(n - 1);
        } else {
            return 2 + bunnies(n - 1);
        }
    }
}