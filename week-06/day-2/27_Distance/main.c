#include <stdio.h>
#include <string.h>

int distance (char input[]);

// create a function which takes a char array as a parameter and
// returns the distance between the first and last occurrence of character 's'

int main()
{
    char str[] = "This is a sample string";

    int dist = distance(str);

    printf("%d", dist);

    return 0;
}

int distance (char input[])
{
    char *first;
    char *last;
    char *temp = strtok(input, "s");
    while (1){
        temp = strtok(NULL, "s");
        first = temp;
        break;
    }
    while (temp != NULL) {
        temp = strtok(NULL, "s");
        if (temp != NULL)
            last = temp;
    }

    return --last - --first;
}