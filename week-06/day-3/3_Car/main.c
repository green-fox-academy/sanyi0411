#include <stdio.h>

// Write a function that takes a car as an argument and prints all it's stats
// If the car is a Tesla it should not print it's gas level

enum car_type {VOLVO, TOYOTA, LAND_ROVER, TESLA};

typedef struct car {
    enum car_type type;
    double km;
    double gas;
} car_t;

void carStats (car_t car);

int main()
{
    car_t myCar;
    car_t yourCar;

    myCar.type = TESLA;
    myCar.km = 50000;
    myCar.gas = 000;

    yourCar.type = VOLVO;
    yourCar.km = 80000;
    yourCar.gas = 5;

    carStats(myCar);
    carStats(yourCar);

    return 0;
}

void carStats (car_t car)
{
    switch (car.type)
    {
        case VOLVO:
            printf("Car type:\tVolvo\nGas:\t\t%.1lf\n", car.gas);
            break;
        case TOYOTA:
            printf("Car type:\tToyota\nGas:\t\t%.1lf\n", car.gas);
            break;
        case LAND_ROVER:
            printf("Car type:\tLand Rover\nGas:\t\t%.1lf\n", car.gas);
            break;
        case TESLA:
            printf("Car type:\tTesla\n");
            break;

    }
    printf("Mileage:\t%.0lfkm\n", car.km);
}