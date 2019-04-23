#include <iostream>
#include "Garden.h"

int main()
{
    Flower yellow(0.0, "yellow");
    Flower blue(0.0, "blue");
    Tree purple(0.0, "purple");
    Tree orange(0.0, "orange");

    Garden myGarden;
    myGarden.addFlower(yellow);
    myGarden.addFlower(blue);
    myGarden.addTree(purple);
    myGarden.addTree(orange);

    myGarden.info();

    myGarden.watering(40);
    myGarden.watering(70);
    return 0;
}