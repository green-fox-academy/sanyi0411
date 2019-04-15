#include <iostream>
#include <fstream>
#include <string>

int main () {
    // Write a program that opens a file called "my-file.txt", then prints
    // each line from the file.
    // You will have to create the file, you may use C-programming, although it is not mandatory

    /*
    std::ofstream myFile ("my-file2.txt");

    if (myFile.is_open())
    {
        myFile << "This is the first line" << std::endl << "This in line 2." << std::endl << "This is line number 3" << std::endl;
    }

    myFile.close();
    */

    std::ifstream inputFile("my-file.txt");

    if (inputFile.fail())
    {
        std::cerr << "Error opening file\n";
        exit (1);
    }

    std::string read;

    while (!inputFile.eof())
    {
        getline(inputFile, read);
        std::cout << read <<std::endl;
    }
    inputFile.close();

return 0;
}