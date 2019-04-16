#include <iostream>
#include <fstream>
#include <string>
#include <exception>

int numberOfLines(std::string);

int main()
{
    // Write a function that takes a filename as string,
    // then returns the number of lines the file contains.
    // It should return zero if it can't open the file

    std::cout << "Number of lines: " << numberOfLines("../Count lines.txt");

    return 0;
}

int numberOfLines(std::string fileName)
{
    std::ifstream myFile;
    myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    int numberOfLines = 0;
    try {
        myFile.open(fileName);
        while (!myFile.eof()) {
            std::string text;
            getline(myFile, text);
            numberOfLines++;
        }
    }
    catch (std::ofstream::failure &e) {
        std::cout << e.what() << std::endl;
    }

    myFile.close();

    return numberOfLines;
}