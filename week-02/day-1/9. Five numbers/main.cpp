#include <iostream>

int main() {
    // Create a program which accepts five integers from the console (given by the user)
    // and store them in an array
    // print out the values of that array using pointers again

    int numbers[5];
    int *numbersPtr = numbers;

    for (int i = 0; i < 5; i++) {
        std::cout << "Enter the " << i + 1 << ". number: " << std::endl;
        std::cin >> numbers[i];
    }

    std::cout << "The values in the array are: \n";
    for (int i = 0; i < 5; i++) {
        std::cout << *(numbersPtr + i) << std::endl;
    }

    return 0;
}