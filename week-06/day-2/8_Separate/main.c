#include <stdio.h>
#include <stdlib.h>
#include "pi.h"

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

int main()
{
    double area = circleArea(1);

    printf("Area: %lf\n", area);

    double circumference = circleCircumference(1);

    printf("Circumference: %lf\n", circumference);

    return 0;
}