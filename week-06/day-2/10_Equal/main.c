#include <stdio.h>
#include <stdlib.h>

int areTheyEqual (int a, int b);

int main()
{
    // Create a program which asks for two integers and stores them separatly
    // Create a function which takes two numbers as parameters and
    // returns 1 if they are equal and returns 0 otherwise

    int a;
    int b;

    printf("Please enter the two numbers\nFirst number:");
    scanf("%d", &a);
    printf("Second number:");
    scanf("%d", &b);

    if(areTheyEqual(a, b))
        printf("They are equal\n");
    else
        printf("They are not equal\n");

    return 0;
}

int areTheyEqual (int a, int b)
{
    if (a == b)
        return 1;
    else
        return 0;
}