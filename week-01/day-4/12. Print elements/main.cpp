#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `numbers`
    //   with the following content: `[4, 5, 6, 7]`
    // - Print all the elements of `numbers`

    int numbers [4] = {4, 5, 6, 7};

    for (int i = 0; i < 3; i++) {
        std::cout << "The " << i + 1 << ". element of the array: " << numbers[i] << std::endl;
    }

return 0;
}