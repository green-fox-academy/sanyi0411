//
// Created by sando on 2019. 04. 24..
//

#include "BassGuitar.h"

BassGuitar::BassGuitar()
{
    _numberOfStrings = 4;
    _sound = "Duum-duum-duum";
    _name = "Bass Guitar";
}

BassGuitar::BassGuitar(int strings)
{
    _numberOfStrings = strings;
    _sound = "Duum-duum-duum";
    _name = "Bass Guitar";
}

void BassGuitar::sound()
{
    std::cout << _sound << std::endl;
}