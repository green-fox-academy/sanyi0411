#include <iostream>

int find (int arr[], int l, int num);

int main() {
    // Create a function which takes an array (and it's length) and a number as a parameter
    // the function should return index where it found the given value
    // if it can't find the number return 0

    int numbers [] = {2, 3, 5, 7, 11, 13, 17};

    //ISSUE: Instructions not clear: the function should return an index
    // or if it did not find a match it should return 0,
    // but 0 is also the index of the first element in the array.
    //Because of this I set the 'No Match' result to -1.

    std::cout << find (numbers, sizeof(numbers) / sizeof(int), 9);

    return 0;
}

int find (int arr[], int l, int num) {
    int index = -1;
    for (int i = 0; i < l; i++) {
        if (arr[i] == num) {
            index = i;
        }
    }
    return index;
}