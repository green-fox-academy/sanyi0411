//
// Created by sando on 2019. 04. 24..
//

#include "Mammal.h"

Mammal::Mammal(std::string name)
{
    _name = name;
}

std::string Mammal::getName()
{
    return _name;
}

std::string Mammal::breed()
{
    return "pushing miniature versions out.";
}
