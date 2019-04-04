#include <iostream>
#include <string>
int main(int argc, char* args[]) {

    // Write a program that asks for an integer that is a distance in kilometers,
    // then it converts that value to miles and prints it

    int km;
    double mile;

    std::cout << "What is your distance in km? (please give an integer)\n";
    std::cin >> km;

    mile = km * 0.62137;

    std::cout << "You are " << mile << " miles away;";

return 0;
}