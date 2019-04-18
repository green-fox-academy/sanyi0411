//
// Created by sando on 2019. 04. 17..
//

#include "Car.h"

Car::Car (int capacity, int gasAmount)
{
    _capacity = capacity;
    _gasAmount = gasAmount;
}

int Car::getCapacity()
{
    return _capacity;
}

int Car::getGasAmount()
{
    return _gasAmount;
}

void Car::setCapacity(int capacity)
{
    Car::_capacity = capacity;
}

void Car::setGasAmount(int gasAmount)
{
    Car::_gasAmount = gasAmount;
}

bool Car::isFull()
{
    if (_gasAmount == _capacity) {
        return true;
    } else {
        return false;
    }
}

void Car::fill()
{
    if (_gasAmount != _capacity) {
        _gasAmount++;
    }
}