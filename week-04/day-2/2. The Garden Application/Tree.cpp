//
// Created by sando on 2019. 04. 23..
//

#include "Tree.h"

Tree::Tree(){}

Tree::Tree(float hasWater, std::string name)
{
    _hasWater = hasWater;
    _name = name;
}

bool Tree::enoughWater()
{
    if (_hasWater < 10) {
        return false;
    } else {
        return true;
    }
}

float Tree::getHasWater() const
{
    return _hasWater;
}

void Tree::setHasWater(float hasWater)
{
    _hasWater = hasWater;
}

void Tree::info()
{
    if(enoughWater()) {
        std::cout << "The " << _name << " tree doesn't need water\n";
    } else {
        std::cout << "The " << _name << " tree needs water\n";
    }
}