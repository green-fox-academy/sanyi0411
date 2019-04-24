//
// Created by sando on 2019. 04. 24..
//

#include "StringedInstrument.h"

StringedInstrument::StringedInstrument() {}

void StringedInstrument::play()
{
    std::cout << _name << ", a " << _numberOfStrings << "-stringed instrument that goes ";
    sound();
}
