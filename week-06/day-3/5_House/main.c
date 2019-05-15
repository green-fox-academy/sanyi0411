#include <stdio.h>

/*
Create a struct that represents a House
It should store:
 - The address of the house
 - The price in EUR
 - The number of rooms
 - The area of the house in square meters
The market price of the houses is 400 EUR / square meters
Create a function that takes a pointer to a house and decides if it's worth to buy
(if the price is lower than the calculated price from it's area)
Create a function that takes an array of houses (and it's length), and counts the
houses that are worth to buy.
*/

typedef struct
{
    char address[100];
    float price;
    int rooms;
    float area;
} house_t;

int worthToBuy (house_t *house);

int howManyWorthToBuy (house_t houses[], int arraySize);

int main()
{
    house_t house1;
    house1.price = 401;
    house1.area = 1;

    house_t house2;
    house2.price = 800;
    house2.area = 2;

    house_t house3;
    house3.price = 1202;
    house3.area = 3;

    printf("%d\n", worthToBuy(&house1));
    printf("%d\n", worthToBuy(&house2));
    printf("%d\n", worthToBuy(&house3));

    house_t housesArray[3] = {house1, house2, house3};

    printf("%d\n", howManyWorthToBuy(housesArray, 3));

    return 0;
}

int worthToBuy (house_t *house)
{
    if ((house->price / house->area) <= 400)
        return 1;
    else
        return 0;
}

int howManyWorthToBuy (house_t houses[], int arraySize)
{
    int counter = 0;
    for (int i = 0; i < arraySize; ++i) {
        if (worthToBuy(&houses[i]))
            counter++;
    }
    return counter;
}