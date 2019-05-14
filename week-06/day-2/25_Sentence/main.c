#include <stdio.h>
#include <string.h>

// create a function which takes a char array as a parameter,
// and splits a string to words by space
// solve the problem with the proper string.h function

void split (char sentence[]);

int main()
{
    char string[256];
    puts("Type in a sentence:\n\n");
    gets(string);

    split(string);

    return 0;
}

void split (char sentence[])
{
    char *word = strtok(sentence, " ");
    while (word != NULL) {
        puts(word);
        word = strtok(NULL, " .");
    }
}