//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_STRINGEDINSTRUMENT_H
#define INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_STRINGEDINSTRUMENT_H

#include "Instrument.h"

class StringedInstrument : public Instrument {
public:
    StringedInstrument();

    virtual void sound() = 0;
    void play();

protected:
    int _numberOfStrings;
};


#endif //INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_STRINGEDINSTRUMENT_H
