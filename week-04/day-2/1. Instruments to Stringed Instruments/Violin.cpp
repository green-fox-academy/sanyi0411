//
// Created by sando on 2019. 04. 24..
//

#include "Violin.h"

Violin::Violin()
{
    _numberOfStrings = 4;
    _sound = "Screech";
    _name = "Violin";
}

void Violin::sound()
{
    std::cout << _sound << std::endl;
}