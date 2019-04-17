//
// Created by sando on 2019. 04. 17..
//

#include "Counter.h"
#include <iostream>

Counter::Counter(int number)
{
    _number = number;
    _resetValue = number;
}

Counter::Counter ()
{
    setNumber(0);
    _resetValue = 0;
}

int Counter::getNumber()
{
    return _number;
}

void Counter::setNumber(int number)
{
    Counter::_number = number;
}

void Counter::add(int number)
{
    int num = getNumber();
    setNumber(num+number);
}

void Counter::add()
{
    int num = getNumber();
    setNumber(num+1);
}

int Counter::get()
{
    return getNumber();
}

void Counter::reset()
{
    setNumber(_resetValue);
}
