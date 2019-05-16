#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes a string and an integer as a parameter.
// The function should return a string where the input string is repeating. The number of repetition is based on the value of the integer parameter.
// For example: Apple, 5 -> AppleAppleAppleAppleApple
// Try to use the least amount of memory that's possible.

char *repeater(char input[], int number);

int main()
{
    char string[] = "Android";

    char *result = repeater(string, 6);

    printf("%s", result);

    free(result);
    result = NULL;

    return 0;
}

char *repeater(char input[], int number)
{
    int size = strlen(input);

    char *pointer = NULL;

    pointer = (char *)calloc(size * number, sizeof(char));

    int n = 0;
    for (int i = 0; i < number; ++i) {
        for (int j = 0; j < size; ++j) {
            pointer[j + n] = input[j];
        }
        n += size;
    }
    return pointer;
}