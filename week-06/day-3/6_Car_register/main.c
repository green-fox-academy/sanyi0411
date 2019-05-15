#include <stdio.h>
#include <string.h>

/* Write a car register!
 * You should store the following data in a structure, called "car":
 *  - the manufacturer's name (which is shorter than 256 characters)
 *  - the price of the car (in euros, stored as a floating point number)
 *  - the year of manufacture
 *  - the type of the transmission (as a custom type, see below)
 *
 * You should store the transmission type in an enumeration ("transmission"),
 * the valid types are:
 *  - manual
 *  - automatic
 *  - CVT
 *  - semi-automatic
 *  - dual-clutch
 *
 * The "car"-s are stored in an array.
 *
 * Write the following functions:
 *  - get_older_cars_than(struct car* array, int array_length, int age)
 *      - it returns the count of the older cars than "age"
 *  - get_transmission_count(struct car* array, int array_length, enum transmission trnsm)
 *      - it returns the count of cars which has "trnsm" transmission
 */

#define currentYear 2019

typedef enum {
    MANUAL,
    AUTOMATIC,
    CVT,
    SEMI_AUTOMATIC,
    DUAL_CLUTCH
}transmission;

typedef struct
{
    char manufacturer[256];
    float price;
    int year;
    transmission transm;
} car_t;

int get_older_cars_than(car_t cars[], int arraySize, int age);

int get_transmission_count(car_t cars[], int arraySize, transmission transm);

int main()
{
    car_t car1;
    car1.year = 2015;
    car1.transm = MANUAL;

    car_t car2;
    car2.year = 2010;
    car2.transm = AUTOMATIC;

    car_t car3;
    car3.year = 2005;
    car3.transm = CVT;

    car_t car4;
    car4.year = 2000;
    car4.transm = MANUAL;

    car_t cars[] = {car1, car2, car3, car4};

    printf("%d\n", get_older_cars_than(cars, 4, 10));

    printf("%d\n", get_transmission_count(cars, 4, MANUAL));

    return 0;
}

int get_older_cars_than(car_t cars[], int arraySize, int age)
{
    int counter = 0;
    for (int i = 0; i < arraySize; ++i) {
        if (cars[i].year < (currentYear - age))
            counter++;
    }
    return counter;
}

int get_transmission_count(car_t cars[], int arraySize, transmission transm)
{
    int counter = 0;
    for (int i = 0; i < arraySize; ++i) {
        if (cars[i].transm == transm)
            counter++;
    }
    return counter;
}