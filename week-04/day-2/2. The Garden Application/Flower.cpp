//
// Created by sando on 2019. 04. 23..
//

#include "Flower.h"

Flower::Flower(){}

Flower::Flower(float hasWater, std::string name)
{
    _hasWater = hasWater;
    _name = name;
}

bool Flower::enoughWater()
{
    if (_hasWater < 5) {
        return false;
    } else {
        return true;
    }
}

void Flower::setHasWater(float hasWater)
{
    _hasWater = hasWater;
}

float Flower::getHasWater() const
{
    return _hasWater;
}

void Flower::info()
{
    if(enoughWater()) {
        std::cout << "The " << _name << " flower doesn't need water\n";
    } else {
        std::cout << "The " << _name << " flower needs water\n";
    }
}
