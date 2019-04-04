#include <iostream>

int main(int argc, char* args[]) {

    // Write a program that asks for two integers
    // The first represents the number of chickens the farmer has
    // The second represents the number of pigs owned by the farmer
    // It should print how many legs all the animals have

    int chicken;
    int pig;

    std::cout << "How many chickens does the farmer have?\n";
    std::cin >> chicken;

    std::cout << "How many pigs does the farmer have?\n";
    std::cin >> pig;

    std::cout << "The animals have a total of " << (chicken * 2) + (pig * 4) << " legs";

    return 0;
}