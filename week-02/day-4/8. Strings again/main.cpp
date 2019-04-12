#include <iostream>

std::string x2y(std::string input);

int main() {

    //Given a string, compute recursively a new string where all the 'x' chars have been removed.

    std::string input = "abcxxdxexfgX";
    std::string output = x2y(input);
    std::cout << output << std::endl;
    return 0;
}

std::string x2y(std::string input) {
    if (input.size() == 0) {
        return "";
    }
    if (input.at(input.length() - 1) == 'x') {
        input.replace(input.length() - 1, 1, "");
        return x2y((input));
    }
    char lastCharacter = input.at(input.size() - 1);
    input.pop_back();
    return x2y(input) + lastCharacter;
}
