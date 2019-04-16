#include <iostream>
#include <fstream>
#include <string>

// Write a function that reads all lines of a file and writes the read lines to an other file (a.k.a copies the file)
// It should take the filenames as parameters
// It should return a boolean that shows if the copy was successful

bool copyLines (std::string read, std::string write);

int main() {

    copyLines("../original.txt", "../copied.txt");

    if (copyLines("../original.txt", "../copied.txt")) {
        std::cout << "Successfully copied\n";
    } else {
        std::cout << "Copying failed\n";
    }

    return 0;
}

bool copyLines(std::string read, std::string write)
{
    bool successful = true;
    std::ifstream readFromThis;
    std::ofstream writeToThis;
    readFromThis.exceptions(std::ifstream::badbit);
    writeToThis.exceptions(std::ofstream::failbit | std::ofstream::badbit);

    try {
        readFromThis.open(read);
        writeToThis.open (write);
        std::string line;
        while (getline(readFromThis, line)) {
            writeToThis << line << std::endl;
        }

    } catch  (std::fstream::failure &e) {
        std::cout << e.what() << std::endl;
        successful = false;
    }

    return successful;
}