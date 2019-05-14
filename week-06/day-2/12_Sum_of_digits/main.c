#include <stdio.h>
#include <stdlib.h>

int sumOfDigitsAreEqual (int nummber1, int number2);
int sumOfDigits (int number);

int main()
{
    // Create a program which asks for two numbers and stores them
    // Create a function which takes two numbers as parameters
    // and returns 1 if the sum of the number of digits are equal and 0 otherwise
    //
    // For example:
    //
    // Case 1:
    //
    // a = 123
    // b = 321
    //
    // sum of number of digits (variable a) = 1 + 2 + 3 = 6
    // sum of number of digits (variable b) = 3 + 2 + 1 = 6
    // in this case the function should return 1
    //
    //
    // Case 2:
    //
    // a = 723
    // b = 114
    //
    // sum of number of digits (variable a) = 7 + 2 + 3 = 12
    // sum of number of digits (variable b) = 1 + 1 + 4 = 6
    // in this case the function should return 0

    int number1;
    int number2;

    printf("Enter 2 numbers (integers)\nFirst number:");
    scanf("%d", &number1);
    printf("Second number:");
    scanf("%d", &number2);

    if (sumOfDigitsAreEqual(number1, number2)) printf("The sum of digits in these numbers are equal\n");
    else printf("The sum of digits in these numbers are not equal\n");

    return 0;
}

int sumOfDigitsAreEqual (int nummber1, int number2)
{
    if (sumOfDigits(nummber1) == sumOfDigits(number2)) return 1;
    else return 0;
}

int sumOfDigits (int number)
{
    int sum = 0;
    while (number != 0) {
        sum = sum + (number % 10);
        number = number / 10;
    }
    return sum;
}
