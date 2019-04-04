#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create an array variable named `aj`
    //   with the following content: `[3, 4, 5, 6, 7]`
    // - Reverse the order of the elements in `aj`
    // - Print the elements of the reversed `aj`

    int aj[5] = {3, 4, 5, 6, 7};

    for (int i = 0; i < (5/2); i++) {
        int z = 4 - i;
        int c = aj[i];
        aj[i] =  aj[z];
        aj[z] = c;
    }

    for (int i = 0; i < 5; i++){
        std::cout << aj[i] << std::endl;
    }

    return 0;
}