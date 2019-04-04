#include <iostream>
#include <string>
#include <vector>

void swap (int& a, int& b) {
    int s = a;
    a = b;
    b = s;
}

int bubble (int arr[], int size) {
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

int unique (int arr[], int size) {
    std::vector <int> a;
    for (int i = 0; i < size; i++) {
        if (arr[i] != arr[i + 1]) {
            a.push_back(arr[i]);
        }
    }
    for (int j = 0; j < a.size(); j++) {
        std::cout << a[j] << std::endl;
    }


}


int main(int argc, char* args[]) {

    //  Create a function that takes a list of numbers as a parameter
    //  Don't forget you have to pass the size of the list as a parameter as well
    //  Returns a list of numbers where every number in the list occurs only once

    /*  Example
    int numbers[] = {1, 11, 34, 11, 52, 61, 1, 34};
    std::cout << (unique(numbers)) << std::endl;
    should print: `[1, 11, 34, 52, 61]`
    */

    int n;
    std::cout << "How many numbers do you have?\n";
    std::cin >> n;
    int numbers [n];

    for (int i = 0; i < n; i++) {
        std::cout << "Enter the " << i + 1 << ". number: \n";
        std::cin >> numbers[i];
    }

    int size = sizeof(numbers) / sizeof(int);

    bubble(numbers, size);

    unique(numbers, size);

    return 0;
}