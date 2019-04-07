#include <iostream>

int main() {
    // Create a pointer for each variable and print out the memory addresses of that variables
    // Print out the values of the pointers

    int a = 31;
    double b = 432.2;
    std::string name = "Bob";

    int *aPtr = &a;
    double *bPtr = &b;
    std::string *namePtr = &name;

    std::cout << "The memory address of 'aPtr' is: " << &aPtr << std::endl;
    std::cout << "The memory address of 'bPtr' is: " << &bPtr << std::endl;
    std::cout << "The memory address of 'namePtr' is: " << &namePtr << std::endl;

    std::cout << "The value pointed to by aPtr is: " << *aPtr << std::endl;
    std::cout << "The value pointed to by bPtr is: " << *bPtr << std::endl;
    std::cout << "The value pointed to by namePtr is: " << *namePtr << std::endl;

    return 0;
}