#include <iostream>
#include <math.h>
int main(int argc, char* args[]) {

    double massInKg = 81.2;
    double heightInM = 1.78;

    // Print the Body mass index (BMI) based on these values

    double BMI = massInKg / pow (heightInM, 2);

    std::cout << "Your BMI is: " << BMI;

    return 0;
}