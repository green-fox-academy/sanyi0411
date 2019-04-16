#include <iostream>
#include <fstream>
#include <string>

int main() {
    // Open a file called "my-file.txt"
    // Write your name in it as a single line

    std::ofstream myFile ("../my-file.txt");
    if (myFile.fail()) {
        std::cout << "Error opening file\n";
        exit (1);
    }

    myFile << "Sandor Derda";

    myFile.close();

    /*Alternate solution:

    std::ofstream myFile;
    myFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);

    try
    {
        myFile.open("../my-file.txt");
        myFile << "Sandor Derda\n";
        myFile.close();
    } catch (std::ofstream::failure& e)
    {
        std::cout << e.what() << std::endl;
    }
    */

    return 0;
}