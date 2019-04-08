#include <iostream>

int *maxSearch (int array[], int arraySize);

int main() {

    int size;
    std::cout << "Enter the size of the array: " << std::endl;
    std::cin >> size;

    int array[size];

    for (int i = 0; i < size; i++) {

        std::cout << "Enter the " << i + 1 << ". number: \n";
        std::cin >> array[i];
    }
    int arraySize = sizeof(array) / sizeof(int);
    std::cout << "The biggest number in this array is: " << *(maxSearch(array, arraySize)) <<
        '\n' << "This element's address is: " << maxSearch(array, arraySize);

    return 0;
}

int *maxSearch (int array[], int arraySize) {
    int *ptr = nullptr;
    int max = array[0];
    int indexOfMax = 0;
    for (int i = 1; i < arraySize; i++) {
        if (array[i] > max) {
            max = array[i];
            indexOfMax = i;
        }
    }
    ptr = &array[indexOfMax];
    return ptr;
}