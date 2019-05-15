#include <stdio.h>
#include <string.h>

// Open a file called "my-file.txt"
// Write your name in it as a single line

int main()
{
    FILE *fpntr;
    fpntr = fopen("my-file.txt", "w");

    if (fpntr == NULL) {
        printf("Unable to open file.");
    } else {
        fprintf(fpntr, "Derda ");
        fputs("Sandor", fpntr);
    }

    return 0;
}