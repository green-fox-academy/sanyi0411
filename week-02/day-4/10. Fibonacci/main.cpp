#include <iostream>

int fibonacci (int n);

int main() {

    //Define a recursive fibonacci(n) method that returns the nth fibonacci number,
    // with n=0 representing the start of the sequence.

    std::cout << fibonacci(12) << std::endl;  //Tested for the 10th, 11th and 12th Fibonacci numbers

    return 0;
}

int fibonacci (int n) {
    if (n >= 0) {
        if (n > 2) {
            return (fibonacci(n - 2) + fibonacci(n - 1));
        } else if (n == 1 || n == 2) {
            return 1;
        } else {
            return 0;
        }
    }
}