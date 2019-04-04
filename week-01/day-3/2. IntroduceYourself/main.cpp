#include <iostream>
#include <string>
int main(int argc, char const *argv[])
{
    // Write a program that prints a few details to the terminal window about you
    // It should print each detail to a new line.
    //  - Your name
    //  - Your age
    //  - Your height in meters (as a decimal fraction)
    //
    //  Example output:
    //  John Doe
    //  31
    //  1.87

    std::string name = "Sandor Derda";
    int age = 27;
    float height = 1.91;

    std::cout << name << std::endl;
    std::cout << age << std::endl;
    std::cout << height << std::endl;

    return 0;
}