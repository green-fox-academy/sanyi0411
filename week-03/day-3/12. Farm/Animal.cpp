//
// Created by sando on 2019. 04. 18..
//

#include "Animal.h"

Animal::Animal(std::string name, int hunger, int thirst)
{
    _name = name;
    _hunger = hunger;
    _thirst = thirst;
}

int Animal::getHunger()
{
    return _hunger;
}

int Animal::getThirst()
{
    return _thirst;
}

std::string Animal::getName()
{
    return _name;
}

void Animal::setHunger(int hunger)
{
    _hunger = hunger;
}

void Animal::setThirst(int thirst)
{
    _thirst = thirst;
}

void Animal::setName(std::string name)
{
    _name = name;
}

void Animal::eat () {
    int food = getHunger();
    setHunger(food-1);
}

void Animal::drink() {
    int water = getThirst();
    setThirst(water-1);
}

void Animal::play () {
    int food = getHunger();
    setHunger(food+1);
    int water = getThirst();
    setThirst(water+1);
}