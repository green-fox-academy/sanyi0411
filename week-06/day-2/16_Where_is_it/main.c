#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int whereIsIt(char word[], char c);

int main()
{
    // Create a program which asks for a string and a character and stores them
    // Create a function which takes a string and a character as a parameter and
    // if the given character is in the string, it should return the index of the
    // first appearance (in the given string) otherwise the function should return -1
    //
    // Example:
    //
    // Case 1:
    //
    // given_string = "embedded"
    // given_char = 'd'
    //
    // the function should return: 4, because this is the index of the first appearance of char 'd'
    //
    //
    // Case 2:
    //
    // given_string = "embedded"
    // given_char = 'a'
    //
    // the function should return: -1, because there is no 'a' in the word "embedded"

    char string[100];
    char letter;

    printf("Enter a word:");
    scanf("%s", string);
    printf("Enter a character:");
    scanf(" %c", &letter);

    if (whereIsIt(string, letter) == -1)
        printf("The letter does not appear in the word\n");
    else
        printf("The letter is at index %d\n", whereIsIt(string, letter));

    return 0;
}

int whereIsIt(char word[], char c)
{
    if (strlen(word) == 0) {
        printf("No word entered!");
        return -1;
    }
    for (int i = 0; i < strlen(word); ++i) {
        if (word[i] == c) return i;
    }
    return -1;
}