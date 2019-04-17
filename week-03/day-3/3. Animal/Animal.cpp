//
// Created by sando on 2019. 04. 17..
//

#include "Animal.h"

Animal::Animal()
{
    _hunger = 50;
    _thirst = 50;
}

int Animal::getHunger()
{
    return _hunger;
}

int Animal::getThirst()
{
    return _thirst;
}

void Animal::setHunger(int hunger)
{
    _hunger = hunger;
}

void Animal::setThirst(int thirst)
{
    _thirst = thirst;
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