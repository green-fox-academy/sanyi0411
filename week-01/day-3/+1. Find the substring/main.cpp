#include <iostream>
#include <string>


int substring (std::string x, std::string y);


int main() {

    //  Create a function that takes two strings as a parameter
    //  Returns the starting index where the second one is starting in the first one
    //  Returns `-1` if the second string is not in the first one

    std::string a = "abbaeddaacdc";
    std::string b = "edda";

    if (substring(a, b) != -1) {
        std::cout << "The substring (" << b << ") starts at the " << substring(a, b)
                  << ". character of the main string (" << a << ")" << std::endl;
    } else {
        std::cout << substring(a, b) << std::endl;
    }

    return 0;
}


int substring (std::string x, std::string y) {
    int st = -1;
    int stt = 0;
    bool sta = false;
    for (int i = 0; i <= (x.length() - y.length()); i++) {
        if (x[i] == y[0]) {
            stt = i + 1;
            for (int j = 0; j < y.length(); j++) {
                if (y[j] == x[j + i]) {
                    sta = true;
                }
            }
        }
    }
    if (sta == true) {
        st = stt;
    }
    return st;
}