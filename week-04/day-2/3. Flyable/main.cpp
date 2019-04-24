#include <iostream>
#include "Flyable.h"
#include "Helicopter.h"

int main()
{
    Helicopter helicopter;
    helicopter.fly();
    helicopter.takeOff();
    helicopter.land();

    return 0;
}