//
// Created by sando on 2019. 04. 18..
//

#include "Farm.h"

Farm::Farm (std::vector<Animal> animal, int maxAnimals)
{
    _animal = animal;
    _maxAnimals = maxAnimals;
}

int Farm::freePlaces () {
    return _maxAnimals - _animal.size();
}

void Farm::breed (std::string name, int hunger, int thirst)
{
    if (freePlaces() > 0) {
        _animal.push_back(Animal(name, hunger, thirst));
    } else {
        std::cout << "The farm is already full\n";
    }
}

void Farm::slaughter ()
{
    int index = 0;
    int hunger = _animal[0].getHunger();
    for (int i = 1; i < _animal.size(); i++) {
        if (_animal[i].getHunger() < hunger) {
            hunger = _animal[i].getHunger();
            index = i;
        }
    }
    _animal.erase(_animal.begin() + index);
}

void Farm::print ()
{
    for (int i = 0; i < _animal.size(); i++){
        std::cout << _animal[i].getName() << std::endl;
    }
}