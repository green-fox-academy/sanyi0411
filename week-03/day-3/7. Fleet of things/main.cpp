#include <iostream>
#include "fleet.h"

int main(int argc, char* args[])
{
    Fleet fleet;
    // Create a fleet of things to have this output:
    // 1. [ ] Get milk
    // 2. [ ] Remove the obstacles
    // 3. [x] Stand up
    // 4. [x] Eat lunch

    Thing task1("Get milk");
    Thing task2("Remove the obstacle");
    Thing task3("Stand up");
    Thing task4("Eat lunch");

    task3.complete();
    task4.complete();

    fleet.add(task1);
    fleet.add(task2);
    fleet.add(task3);
    fleet.add(task4);

    std::cout << fleet.toString() << std::endl;
    return 0;
}