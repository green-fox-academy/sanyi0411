#include <stdio.h>

/*
Create a sandwich struct
It should store:
 - name
 - price (float)
 - weight (float)
Create a function which takes two parameters and returns the price of your order.
The parameters should be:
 - a sandwich struct
 - and an integer that represents how many sandwiches you want to order
*/

typedef struct
{
    char name[10];
    float price;
    float weight;
} sandwich_t;

float totalPrice (sandwich_t sandwich, int numberOfSandwiches);

int main()
{
    sandwich_t sandwich;
    sandwich.price = 2.45;
    printf("%.2f", totalPrice(sandwich, 2));

    return 0;
}

float totalPrice(sandwich_t sandwich, int numberOfSandwiches)
{
    return numberOfSandwiches * sandwich.price;
}