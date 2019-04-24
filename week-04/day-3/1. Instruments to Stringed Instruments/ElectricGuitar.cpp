//
// Created by sando on 2019. 04. 24..
//

#include "ElectricGuitar.h"

ElectricGuitar::ElectricGuitar()
{
    _numberOfStrings = 6;
    _sound = "Twang";
    _name = "Electric Guitar";
}

ElectricGuitar::ElectricGuitar(int strings)
{
    _numberOfStrings = strings;
    _sound = "Twang";
    _name = "Electric Guitar";
}

void ElectricGuitar::sound()
{
    std::cout << _sound << std::endl;
}