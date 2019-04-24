//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_ELECTRICGUITAR_H
#define INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_ELECTRICGUITAR_H

#include <iostream>
#include "StringedInstrument.h"

class ElectricGuitar : public StringedInstrument {
public:
    ElectricGuitar();
    ElectricGuitar(int strings);

    void sound();

protected:
    std::string _sound;
};


#endif //INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_ELECTRICGUITAR_H
