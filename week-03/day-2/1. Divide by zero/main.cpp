#include <iostream>
#include <fstream>

void divideByTen (int number);

int main()
{
    // Create a function that takes a number
    // divides ten with it,
    // and prints the result.
    // It should print "fail" if the parameter is 0

    int input;
    std::cout << "Enter a number\n";
    std::cin >> input;

    divideByTen(input);

    return 0;
}

void divideByTen (int number)
{
    try {
        if (number == 0)
        {
            throw 0;
        }
    }
    catch(...)
    {
        std::cout << "Cannot divide by 0\n";
    }
    std::cout << 10 / number << std::endl;


}