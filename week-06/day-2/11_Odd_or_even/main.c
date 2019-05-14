#include <stdio.h>
#include <stdlib.h>

int oddOrEven (int input);

int main()
{
    // Create a program which asks for a number and stores it
    // Create a function which takes a number as a parameter and
    // returns 1 if that number is even and returns 0 otherwise
    // (in this case 0 is an even number)

    int input;

    printf("Please enter a number (interger):");
    scanf("%d", &input);

    if (oddOrEven(input)) printf("It is an even number\n");
    else printf("It is an odd number\n");

    return 0;
}

int oddOrEven (int input)
{
    if (input % 2 == 0) return 1;
    else return 0;
}