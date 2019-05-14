#include <stdio.h>

int main()
{
    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Use variables to store the informations!
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87

    char myName[] = "Sandor Derda";
    int myAge = 27;
    float myHeight = 1.92;

    printf("%s\n", myName);
    printf("%d\n", myAge);
    printf("%.2f\n", myHeight);

    return 0;
}