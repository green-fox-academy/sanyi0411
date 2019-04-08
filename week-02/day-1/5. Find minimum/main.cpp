#include <iostream>

int *minimum (int array[], int length);

int main() {
    // Create a function which takes an array (and its length) as a parameter
    // and returns a pointer to its minimum value

    int numbers[] = {12, 4, 66, 101, 87, 3, 15};
    int numbersSize = sizeof(numbers) / sizeof(int);

    std::cout << "The minumum value in this array is: " << *(minimum (numbers, numbersSize)) << std::endl;
    std::cout << "This element's memory address is: " << minimum (numbers, numbersSize) << std::endl;
    //std::cout << &numbers[5] << std::endl;

return 0;
}

int *minimum (int array[], int length) {
    int *ptr = nullptr;
    int smallest = array[0];
    int indexOfSmallest = 0;
    for (int i = 1; i < length; i++) {
        if (array[i] < smallest) {
            smallest = array[i];
            indexOfSmallest = i;
        }
    }
    ptr = &array[indexOfSmallest];
    return ptr;
}