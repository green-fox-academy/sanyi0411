#include <iostream>
#include <string>

int main(int argc, char* args[]) {

    // - Create (dynamically) a two dimensional array
    //   with the following matrix. Use a loop!
    //   by dynamically, we mean here that you can change the size of the matrix
    //   by changing an input value or a parameter or this combined
    //
    //   1 0 0 0
    //   0 1 0 0
    //   0 0 1 0
    //   0 0 0 1
    //
    // - Print this two dimensional array to the output

    int size;
    std::cout << "Enter the size of the diagonal: \n";
    std::cin >> size;

    int a;
    int b;
    std::cout << "What numbers should the diagonal be made of: \n";
    std::cin >> a;
    std::cout << "What numbers should fill up the rest of the square: \n";
    std::cin >> b;

    int array [size][size];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                array[i][j] = a;
            } else {
                array[i][j] = b;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) {
                std::cout << array[i][j];
            } else {
                std::cout << array[i][j];
            }
        }
        std::cout << std::endl;
    }
    return 0;
}