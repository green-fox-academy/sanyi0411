#include <iostream>
#include <string>

//  Create a function that takes a list of numbers as parameter
//  Don't forget you have to pass the size of the list as a parameter as well
//  Returns a list where the elements are sorted in ascending numerical order by using bubble sort
//  Make a second boolean parameter, if it's `true` sort that list descending


void swap (int& a, int& b) {
    int s = a;
    a = b;
    b = s;
}

int bubble_asc (int arr[], int size) {
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

int bubble_des (int arr[], int size) {
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            if (arr[i] < arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

int main(int argc, char* args[]) {

    int a[] = {1, 5, 3, 4, 7, 6, 2};
    int size = sizeof(a) / sizeof(int);

    bool f = false;

    if (f == false) {
        bubble_asc(a, size);
    } else {
        bubble_des (a, size);
    }
    for (int i = 0; i < size; i++){
        std::cout << a[i] <<std::endl;
    }


return 0;
}