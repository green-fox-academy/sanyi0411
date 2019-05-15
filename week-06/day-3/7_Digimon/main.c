#include <stdio.h>
#include <string.h>

typedef enum
{
    BABY,
    IN_TRAINING,
    ROOKIE,
    CHAMPION,
    ULTIMATE,
    MEGA
} digivolution;

typedef struct
{
    char name[127];
    int age;
    int health;
    char tamer[255];
    digivolution digiv;
} digimon_t;

int get_minimum_health_index (digimon_t digis[], int arraySize);

int get_same_digivolution_level_count (digimon_t digis[], int arraySize, digivolution digiv);

int get_same_tamer_count (digimon_t digis[], int arraySize, char tamerName[]);

float get_average_health_of_the_same_tamer (digimon_t digis[], int arraySize, char tamerName[]);

int main()
{
    digimon_t digimon1;
    digimon1.health = 10;
    digimon1.digiv = 1;
    strcpy(digimon1.tamer, "John");

    digimon_t digimon2;
    digimon2.health = 20;
    digimon2.digiv = 2;
    strcpy(digimon2.tamer, "Bob");

    digimon_t digimon3;
    digimon3.health = 30;
    digimon3.digiv = 3;
    strcpy(digimon3.tamer, "John");

    digimon_t digimon4;
    digimon4.health = 40;
    digimon4.digiv = 2;
    strcpy(digimon4.tamer, "Bob");

    digimon_t digimonsArray[] = {digimon1, digimon2, digimon3, digimon4};

    printf("%d\n", get_minimum_health_index(digimonsArray, 4));

    printf("%d\n", get_same_digivolution_level_count(digimonsArray, 4, 2));

    printf("%d\n", get_same_tamer_count(digimonsArray, 4, "John"));

    printf("%.2lf\n", get_average_health_of_the_same_tamer(digimonsArray, 4, "Bob"));

    return 0;
}

int get_minimum_health_index (digimon_t digis[], int arraySize)
{
    int index = 0;
    int minHealth = digis->health;
    for (int i = 0; i < arraySize; ++i) {
        if (digis[i].health < minHealth) {
            minHealth = digis[i].health;
            index = i;
        }
    }
    return index;
}

int get_same_digivolution_level_count (digimon_t digis[], int arraySize, digivolution digiv)
{
    int counter = 0;
    for (int i = 0; i < arraySize; ++i) {
        if (digis[i].digiv == digiv)
            counter++;
    }
    return counter;
}

int get_same_tamer_count (digimon_t digis[], int arraySize, char tamerName[])
{
    int counter = 0;
    for (int i = 0; i < arraySize; ++i) {
        if (!strcmp(digis[i].tamer, tamerName)) {
            counter++;
        }
    }
    return counter;
}

float get_average_health_of_the_same_tamer (digimon_t digis[], int arraySize, char tamerName[])
{
    int counter = 0;
    int sumHealth = 0;
    for (int i = 0; i < arraySize; ++i) {
        if (!strcmp(digis[i].tamer, tamerName)) {
            counter++;
            sumHealth += digis[i].health;
        }
    }
    if (counter == 0) {
        printf("No tamer with the given name!");
        return -1;
    }
    return sumHealth / counter;
}