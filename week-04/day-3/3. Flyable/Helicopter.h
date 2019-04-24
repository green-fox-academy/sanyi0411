//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_3__FLYABLE_HELICOPTER_H
#define INC_3__FLYABLE_HELICOPTER_H

#include <iostream>
#include "Vehicle.h"
#include "Flyable.h"

class Helicopter : public Vehicle, public Flyable {
public:
    void land();
    void fly();
    void takeOff();

};


#endif //INC_3__FLYABLE_HELICOPTER_H
