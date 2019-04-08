#include <iostream>

int main() {
    // Create a program which first asks for a number
    // this number indicates how many integers we want to store in an array
    // and than asks for numbers till the user fills the array
    // It should print out the biggest number in the given array and the memory address of it

    int size;
    std::cout << "Enter the size of the array: " << std::endl;
    std::cin >> size;

    int array[size];

    for (int i = 0; i < size; i++) {

        std::cout << "Enter the " << i + 1 << ". number: \n";
        std::cin >> array[i];
    }

    int max = array[0];
    int indexOfHighestNumber = 0;

    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
            indexOfHighestNumber = i;
        }
    }

    std::cout << "The biggest number in the array is: " << max << std::endl << "This number's memory address is: " << &array[indexOfHighestNumber] << std::endl;

return 0;
}