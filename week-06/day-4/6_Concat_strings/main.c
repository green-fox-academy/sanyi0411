#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// write a function which takes 2 strings as parameter, concatenates them together and returns it back.
// Test it for long and empty strings as well.
// Try to use the least amount of memory that's possible.

char *concatenate (char string1[], char  string2[]);
char *read_string();

int main()
{
    printf("Enter the first string:\n");
    char *input1 = read_string();
    printf("Enter the second string:\n");
    char *input2 = read_string();

    char *result = concatenate(input1, input2);

    printf("%s", result);

    free(input1);
    input1 = NULL;
    free(input2);
    input2 = NULL;

    return 0;
}

char *concatenate (char string1[], char string2[])
{
    int size = strlen(string1) + strlen(string2);

    char *result = NULL;

    result = (char *)calloc(1, size + 1);

    for (int i = 0; i < strlen(string1); ++i) {
        result[i] = string1[i];
    }

    for (int j = 0; j < strlen(string2); ++j) {
        result[j + strlen(string1)] = string2[j];
    }

    result[size] = '\0';

    return result;
}

char *read_string()
{
    size_t size = 1;
    char *string = (char *)calloc(size, sizeof(char));

    // Read a character from the standard input
    char c = getc(stdin);

    // Check if the character is not '\n'
    while (c != '\n') {
        // Reallocate the memory for the string to fit one more character
        size++;
        string = (char *) realloc(string, size * sizeof(char));

        // Append the character to the end of the string
        string[size - 2] = c;

        // Append a '\0' to the end of the string
        string[size - 1] = '\0';

        // Repeat
        c = getc(stdin);
    }

    return string;
}