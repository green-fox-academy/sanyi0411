#include <stdio.h>
#include <stdlib.h>

int isPrime (int input);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter
    // and returns 1 if the number is a prime number and 0 otherwise
    // (in this case 0 is not considered as a prime number)

    int input;
    printf("Please enter a positive number:");
    scanf("%d", &input);

    if (isPrime(input)) printf("This number is a prime\n");
    else printf("This number is not a prime\n");

    return 0;
}

int isPrime (int input)
{
    if (input == 1) return 0;
    if (input == 2) return 1;

    int t = 3;
    int prime = 1;
    while (prime && t <= input/2) {
        if (input % t == 0) prime = 0;
        t++;
    }
    return prime;
}