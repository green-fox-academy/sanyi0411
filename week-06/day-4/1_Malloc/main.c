#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with 5!! numbers from 0 to 4, then print the whole array
// please delete the array before the program exits

int main()
{
    int *intArray;

    intArray = (int *)malloc(10 * sizeof(int));

    for (int i = 0; i < 5; ++i) {
        intArray[i] = i;
    }

    for (int j = 0; j < 10; ++j) {
        printf("%d\n", intArray[j]);
    }

    free(intArray);

    return 0;
}