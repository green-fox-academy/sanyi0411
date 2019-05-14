#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    // Write a program that stores a number, and the user has to figure it out.
    // The user can input guesses, after each guess the program would tell one
    // of the following:
    //
    // The stored number is higher
    // The stored number is lower
    // You found the number: 8

    srand(time(NULL));
    int r = rand() % 10 + 1;
    int guess;

    printf("Guess a random number between 1 and 10:\n");
    scanf("%d", &guess);

    while (guess != r) {
        if (guess > r) {
            printf("The stored number is lower\nGuess again:\n");
        } else {
            printf("The stored number is higher\nGuess again:\n");
        }
        scanf("%d", &guess);
    }
    printf("You found the number: %d", r);

    return 0;
}