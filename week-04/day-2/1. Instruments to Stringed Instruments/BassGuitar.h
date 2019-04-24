//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_BASSGUITAR_H
#define INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_BASSGUITAR_H

#include <iostream>
#include "StringedInstrument.h"

class BassGuitar : public StringedInstrument {
public:
    BassGuitar();
    BassGuitar(int strings);

    void sound();

protected:
    std::string _sound;
};


#endif //INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_BASSGUITAR_H
