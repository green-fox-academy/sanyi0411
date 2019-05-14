#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *append (char input[]);

int main()
{
    // Create a program which asks for a string and stores it
    // Create a function which takes a string as a parameter and
    // appends a character 'a' to the end of it and returns the new string

    char input[100];

    printf("Enter a word:");
    scanf("%s", input);

    printf("%s", append(input));

    return 0;
}

char *append (char input[])
{
    strcat(input, "a");
    return input;
}