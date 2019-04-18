#include <iostream>
#include "Animal.h"
#include "Farm.h"

std::vector<Animal> initializeFarm ()
{
    std::vector<Animal> animals;

    animals.push_back(Animal("Bessie", 6, 4));
    animals.push_back(Animal("Buttercup", 8, 6));
    animals.push_back(Animal("Daisy", 9, 5));
    animals.push_back(Animal("Milkshake", 5, 5));
    animals.push_back(Animal("MooDonna", 10, 8));
    animals.push_back(Animal("Rosie", 7, 3));

    return animals;

}

int main()
{
    Farm myFarm (initializeFarm(), 10);

    std::cout << "Farm before breed: \n";
    myFarm.print();

    myFarm.breed("Mooana", 8, 2);
    std::cout << "\nFarm after breed: \n";
    myFarm.print();

    myFarm.slaughter();
    std::cout << "\nFarm: after slaughter: \n";
    myFarm.print();



    return 0;
}