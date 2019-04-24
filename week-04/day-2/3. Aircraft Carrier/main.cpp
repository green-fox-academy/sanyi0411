#include <iostream>
#include "Aircraft.h"
#include "Carrier.h"

int main()
{
    Carrier a (0, 100, "myName");
    a.fillAllAircrafts();
    return 0;
}