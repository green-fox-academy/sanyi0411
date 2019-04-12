#include <iostream>

std::string x2y(std::string input);

int main() {

    //Given a string, compute recursively (no loops) a new string
    // where all the lowercase 'x' chars have been changed to 'y' chars.

    std::string input = "abcdxefgX";
    std::string output = x2y(input);
    std::cout << output << std::endl;
    return 0;
}

std::string x2y(std::string input) {
    if (input.size() == 0) {
        return "";
    }
    if (input.at(input.length() - 1) == 'x') {
        input.replace(input.length() - 1, 1, "y");
    }
    char lastCharacter = input.at(input.size() - 1);
    input.pop_back();
    return x2y(input) + lastCharacter;
}
