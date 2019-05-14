#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stringLength (char name[]);

int main()
{
    // Create a program which asks for the name of the user and stores it
    // Create a function which takes a string as a parameter and returns the length of it
    // Solve this exercise with and without using string.h functions

    char name[100];

    printf("Please enter your name:");
    scanf("%s", name);

    int length = stringLength(name);

    printf("Your name is %d characters long\n", length);

    return 0;
}

int stringLength (char name[])
{
    return strlen(name);
}