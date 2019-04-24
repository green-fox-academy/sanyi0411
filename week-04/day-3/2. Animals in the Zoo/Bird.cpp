//
// Created by sando on 2019. 04. 24..
//

#include "Bird.h"

Bird::Bird(std::string name)
{
    _name = name;
}

std::string Bird::getName()
{
    return _name;
}

std::string Bird::breed()
{
    return "laying eggs";
}
