#include <stdio.h>
#include <stdlib.h>

// with malloc
// please allocate a 10 long array and fill it with even numbers then print the whole array
// please deallocate memory without using free

int main()
{
    int *pointer = NULL;

    pointer = (int *)malloc(sizeof(int) * 10);

    int even = 2;

    for (int i = 0; i < 10; ++i) {
        pointer[i] = even;
        even += 2;
    }

    for (int j = 0; j < 10; ++j) {
        printf("%d\n", pointer[j]);
    }

    free(pointer);
    pointer = NULL;

    return 0;
}