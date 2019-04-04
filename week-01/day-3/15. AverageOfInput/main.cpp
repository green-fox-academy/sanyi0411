#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for 5 integers in a row,
    // then it should print the sum and the average of these numbers like:
    //
    // Sum: 22, Average: 4.4
    int t[5];

    for (int i = 0; i<5; i++) {
        std::cout << "Please enter the " << i+1 << ". number: \n";
        std::cin >> t[i];
    }

    int sum = 0;

    for (int i = 0; i<5; i++) {
        sum += t[i];
    }

    double average = sum / 5;

    std::cout << "Sum: " << sum << ", Average: " << average << std::endl;

    return 0;
}