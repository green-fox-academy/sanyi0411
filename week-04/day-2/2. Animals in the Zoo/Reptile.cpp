//
// Created by sando on 2019. 04. 24..
//

#include "Reptile.h"

Reptile::Reptile(std::string name)
{
    _name = name;
}

std::string Reptile::getName()
{
    return _name;
}

std::string Reptile::breed()
{
    return "laying eggs";
}
