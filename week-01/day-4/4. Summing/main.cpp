#include <iostream>
#include <string>

int summing (int);


int main(int argc, char* args[]) {

    // Write a function called `sum` that returns the sum of numbers from zero to the given parameter

    int n;
    std::cout << "Enter a number: \n";
    std::cin >> n;

    std::cout << summing(n) << std::endl;

    return 0;
}

int summing (int a) {
    int sum = 0;
    for (int i = 1; i <= a; i++) {
        sum += i;
    }
    return sum;
}