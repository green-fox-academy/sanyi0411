#include <stdio.h>
#include <stdlib.h>

// Prompt the user to enter a number. -> This number will be X.
// Allocate memory for X numbers.
// Prompt the user to enter X numbers.
// Allocate memory for Y numbers, which is the sum of the X numbers.
// Fill that array with from 1 to Y, then print them.

int main()
{
    int *pointer = NULL;
    int *ptr2 = NULL;

    int x;
    printf("Please enter a number:\n");
    scanf("%d", &x);

    pointer = (int *)malloc(sizeof(int) * x);

    for (int i = 0; i < x; ++i) {
        printf("Enter the %d. number:\n", i + 1);
        scanf("%d", &pointer[i]);
    }

    int y = 0;
    for (int j = 0; j < x; ++j) {
        y += pointer[j];
    }

    ptr2 = (int *)malloc(sizeof(int) * y);

    for (int k = 0; k < y; ++k) {
        ptr2[k] = k + 1;
        printf("%d", ptr2[k]);
    }

    return 0;
}