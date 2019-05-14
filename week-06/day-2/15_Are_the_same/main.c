#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int areTheSame (char string1[], char string2[]);
int comp (const void * elem1, const void * elem2);

int main()
{
    // Create a program which asks for two strings and stores them
    // Create a function which takes two strings as parameters and
    // returns 1 if the two strings are the same and 0 otherwise
    // Try to erase small and uppercase sensitivity.

    char string1[100];
    char string2[100];

    printf("Enter the first string:");
    scanf("%s", string1);
    printf("Enter the second string:");
    scanf("%s", string2);

    if(areTheSame(string1, string2))
        printf("They are the same\n");
    else
        printf("They are not the same\n");

    return 0;
}

int areTheSame (char string1[], char string2[])
{
    if (strlen(string1) != strlen(string2))
        return 0;
    for (int i = 0; i < strlen(string1); ++i) {
        char s1 = tolower(string1[i]);
        char s2 = tolower(string2[i]);
        if (s1 != s2)
            return 0;
    }
    return 1;
}
