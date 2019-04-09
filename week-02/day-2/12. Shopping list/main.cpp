#include <iostream>
#include <vector>
#include <string>

bool have (std::vector<std::string>, std::string);

int main() {

    //Create a list with the following items.
    std::vector<std::string> list = {"eggs", "milk", "fish", "apples", "bread", "chicken"};

    //Do we have milk on the list?
    if (have (list, "milk") == true) {
        std::cout << "We have milk on the list.\n";
    } else {
        std::cout << "We don't have milk on the list.\n";
    }

    //Do we have bananas on the list?
    if (have (list, "bananas") == true) {
        std::cout << "We have bananas on the list.\n";
    } else {
        std::cout << "We don't have bananas on the list.\n";
    }

    return 0;
}

bool have (std::vector<std::string> input, std::string wanted) {
    bool f = false;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == wanted) {
            f = true;
        }
    }
    return f;
}