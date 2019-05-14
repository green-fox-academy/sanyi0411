#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

// define a variable called PI with the value of 3.14
// create a function which takes the radius of a circle as a parameter
// and return the area of that cirle
// area = radius * radius * PI

double circleArea (double radius);

int main()
{
    double area = circleArea(1);

    printf("Area: %lf", area);

    return 0;
}

double circleArea (double radius)
{
    return radius * radius * PI;
}