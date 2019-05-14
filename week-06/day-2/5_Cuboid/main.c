#include <stdio.h>

int main()
{
    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // You should get these variables via console input
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    double x;
    double y;
    double z;

    printf("Enter the 3 sides of the cuboid:\nX:1");
    scanf("%lf", &x);
    printf("Y:");
    scanf("%lf", &y);
    printf("Z:");
    scanf("%lf", &z);

    double area = 2 * (x * y) + 2 * (x * z) + 2 * (y * z);
    double volume = x * y * z;

    printf("Surface area: %lf\n", area);
    printf("Volume: %lf\n", volume);

    return 0;
}