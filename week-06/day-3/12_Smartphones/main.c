#include <stdio.h>
#define currentYear 2019

typedef enum
{
    BIG,
    MEDIUM,
    SMALL
}screen;

typedef struct
{
    char name[255];
    int releaseYear;
    screen screenType;
} smartphone_t;

const char *get_oldest_phone(smartphone_t smartphones[], int arraySize);

int get_screen_size_count(smartphone_t smartphones[], int arraySize, screen screenSize);

int main()
{
    printf("Hello, World!\n");
    return 0;
}

const char *get_oldest_phone(smartphone_t smartphones[], int arraySize)
{
    int maxAge = 0;
    int index = -1;
    for (int i = 0; i < arraySize; ++i) {
        int age = currentYear - smartphones[i].releaseYear;
        if (age > maxAge) {
            maxAge = age;
            index = i;
        }
    }
    return smartphones[index].name;
}

int get_screen_size_count(smartphone_t smartphones[], int arraySize, screen screenSize)
{
    int counter = 0;
    for (int i = 0; i < arraySize; ++i) {
        if (smartphones[i].screenType == screenSize) {
            counter++;
        }
    }
    return counter;
}