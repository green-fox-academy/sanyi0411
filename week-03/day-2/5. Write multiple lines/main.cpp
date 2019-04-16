#include <iostream>
#include <fstream>
#include <string>

void writeToFile(std::string, std::string, int);

// Create a function that takes 3 parameters: a path, a word and a number
// and is able to write into a file.
// The path parameter should be a string that describes the location of the file you wish to modify
// The word parameter should also be a string that will be written to the file as individual lines
// The number parameter should describe how many lines the file should have.
// If the word is "apple" and the number is 5, it should write 5 lines
// into the file and each line should read "apple"

int main()
{
    std::string filePath;
    std::string input;
    int lines;

    std::cout << "Enter the path to file in which you want to write: \n";
    std::cin >> filePath;
    std::cout << "Enter the word you want to write in the file\n";
    std::cin >> input;
    std::cout << "How many lines do you want to write?\n";
    std::cin >> lines;

    writeToFile(filePath, input, lines);

    return 0;
}

void writeToFile(std::string path, std::string word, int lines)
{
    std::ofstream myFile;
    myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try {
        myFile.open (path);
        for (int i = 0; i < lines; i++) {
            myFile << word << std::endl;
        }
    } catch (std::ifstream::failure &e) {
        std::cout << e.what() << std::endl;
    }
}