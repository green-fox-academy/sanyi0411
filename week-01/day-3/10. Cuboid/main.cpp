#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that stores 3 sides of a cuboid as variables (doubles)
    // The program should write the surface area and volume of the cuboid like:
    //
    // Surface Area: 600
    // Volume: 1000

    //Input of data? Should this be a function?

    double a;
    double b;
    double c;

    double surface = (2*a*b)+(2*a*c)+(2*b*c);
    double volume = a*b*c;

    std::cout << "Surface Area: " << surface << std::endl;
    std::cout << "Volume: " << volume << std::endl;

return 0;
}