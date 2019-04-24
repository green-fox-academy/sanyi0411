//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_3_FLYABLE_FLYABLE_H
#define INC_3_FLYABLE_FLYABLE_H

#include <iostream>
#include "Vehicle.h"

class Flyable {
public:
    virtual void land() = 0;
    virtual void fly() = 0;
    virtual void takeOff() = 0;

};


#endif //INC_3_FLYABLE_FLYABLE_H
