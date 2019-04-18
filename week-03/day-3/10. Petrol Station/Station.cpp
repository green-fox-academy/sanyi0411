//
// Created by sando on 2019. 04. 17..
//

#include "Station.h"

Station::Station(int gasAmount)
{
    _gasAmount = gasAmount;
}

int Station::getGasAmount()
{
    return _gasAmount;
}

void Station::setGasAmount(int gasAmount)
{
    Station::_gasAmount = gasAmount;
}

void Station::fillCar(Car &current)
{
    while (!current.isFull()) {
        current.fill();
        _gasAmount--;
        std::cout << "Filling car!\n" ;
    }
}