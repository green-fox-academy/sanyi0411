#include <iostream>
#include <string>
int main(int argc, char *args[]) {

    // Write a program that prints the numbers from 1 to 100.
    // But for multiples of three print “Fizz” instead of the number
    // and for the multiples of five print “Buzz”.
    // For numbers which are multiples of both three and five print “FizzBuzz”.

    std::string a = "";
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0) {
            a += "Fizz";
        }
        if (i % 5 == 0) {
            a += "Buzz";
        }
        if (a == "") {
            std::cout << i << std::endl;
        } else {
            std::cout << a << std::endl;
        }
        a = "";
    }

    return 0;
}