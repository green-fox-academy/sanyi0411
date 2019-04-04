#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for a number.
    // It would ask this many times to enter an integer,
    // if all the integers are entered, it should print the sum and average of these
    // integers like:
    //
    // Sum: 22, Average: 4.4

    int n, z;
    int sum = 0;
    std::cout << "How many numbers do you have?\n";
    std::cin >> n;

    for (int i = 0; i < n; i++) {
        std::cout << "Enter the " << i + 1 << ". number\n";
        std::cin >> z;
        sum += z;
    }

    std::cout << "Sum: " << sum << ", Average: " << sum / n;


    return 0;
}