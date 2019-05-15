#include <stdio.h>
#include <string.h>

// Write a function that takes a filename as string,
// then returns the number of lines the file contains.
// It should return zero if it can't open the file

int lineCounter (char filePath[]);

int main()
{
    printf("%d", lineCounter("my-file.txt"));
    return 0;
}

int lineCounter (char filePath[])
{
    int counter = 0;

    FILE *fpntr;
    fpntr = fopen(filePath, "r");

    if (fpntr == NULL) {
        printf("Unable to open file.");
    } else {
        char buffer[50];
        while (fgets(buffer, 50, fpntr) != NULL) {
            counter++;
        }
    }
    return counter;
}