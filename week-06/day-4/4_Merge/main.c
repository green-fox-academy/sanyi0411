#include <stdio.h>
#include <stdlib.h>

// please allocate a 10 long array and fill it with even numbers
// please allocate a 10 long array and fill it with odd numbers
// select an array, and push the elements into the another array
// print the array in descending order
// delete the arrays after you don't use them

int main()
{
    int *intPtrEven = NULL;
    int *intPtrOdd = NULL;

    intPtrEven = (int *)malloc(sizeof(int) * 10);
    intPtrOdd = (int *)malloc(sizeof(int) * 10);

    int even = 2;
    int odd = 1;

    for (int i = 0; i < 10; ++i) {
        intPtrEven[i] = even;
        even += 2;
        intPtrOdd[i] = odd;
        odd += 2;
    }

    intPtrOdd = realloc(intPtrOdd, sizeof(int) * 20);

    //Make space for even numbers
    for (int k = 0; k < 10; ++k) {
        intPtrOdd[20 - 2 * k] = intPtrOdd[10 - k];
    }

    //Fill up with the even numbers
    for (int j = 0; j < 10; ++j) {
        intPtrOdd[j * 2 + 1] = intPtrEven[j];
    }

    //Print out the elements
    for (int l = 19; l >= 0; --l) {
        printf("%d\n", intPtrOdd[l]);
    }

    free(intPtrEven);
    intPtrEven = NULL;
    free(intPtrOdd);
    intPtrOdd = NULL;

    return 0;
}