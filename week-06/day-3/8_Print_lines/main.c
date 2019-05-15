#include <stdio.h>
#include <string.h>

// Write a program that opens a file called "my-file.txt", then prints
// each line from the file.
// You will have to create the file, for that you may use C-programming, although it is not mandatory

int main()
{
    FILE *fpointer;
    fpointer = fopen("my-file.txt", "r");

    if (fpointer == NULL) {
        printf("Unable to open file.");
    } else {
        char buffer [50];
        while (fgets(buffer, 50, fpointer) != NULL) {
            fprintf(stdout, "%s", buffer);
        }
    }

    return 0;
}