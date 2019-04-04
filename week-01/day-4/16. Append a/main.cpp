#include <iostream>
#include <string>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `animals`
    //   with the following content: `["koal", "pand", "zebr"]`
    // - Add all elements an `"a"` at the end

    std::string animals [3] = {"koal", "pand", "zebr"};

    int a = sizeof(animals) / sizeof(std::string);

    for (int i = 0; i < a; i++) {
        animals[i] = animals[i] + "a";
    }


    /*
    for (int i = 0; i < a; i++) {
        std::cout << animals[i] << std::endl;
    }
    */

    return 0;
}