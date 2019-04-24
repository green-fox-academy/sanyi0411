//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_VIOLIN_H
#define INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_VIOLIN_H

#include <iostream>
#include "StringedInstrument.h"

class Violin : public StringedInstrument {
public:
    Violin();

    void sound();

protected:
    std::string _sound;
};


#endif //INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_VIOLIN_H
