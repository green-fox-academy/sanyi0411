#include <stdio.h>
#include <string.h>

void position (char input[]);

// create a function which takes a char array as a parameter and
// lists all position where character 'i' is found

int main ()
{
    char string[55] = "This is a string for testing";
    char *p;

    position(string);

    return 0;
}

void position (char input[])
{
    for (int i = 0; i < strlen(input); ++i) {
        if(input[i] == 'i')
            printf("Index: %d\n", i);
    }
}