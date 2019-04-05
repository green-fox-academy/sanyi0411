#include <iostream>
#include <string>

std::string create_palindrome (std::string x);

int main() {

    std::string a = "greenfox";
    std::cout << create_palindrome(a) << std::endl;

    return 0;
}

std::string create_palindrome (std::string x) {
    std::string palindrome = x;
    for (int i = x.length() - 1; i >= 0; i--) {
        palindrome += x[i];
    }

    return palindrome;
}