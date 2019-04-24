//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_INSTRUMENT_H
#define INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_INSTRUMENT_H

#include <iostream>

class Instrument {
public:
    Instrument();

    virtual void play() = 0;

protected:
    std::string _name;
};


#endif //INC_1__INSTRUMENTS_TO_STRINGED_INSTRUMENTS_INSTRUMENT_H
