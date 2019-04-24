//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_3__FLYABLE_VEHICLE_H
#define INC_3__FLYABLE_VEHICLE_H

#include <iostream>

enum Type {
    FLYABLE,
    LAND,
    WATER
};

class Vehicle {
public:

protected:
    Type _type;
    std::string _color;
    int _yearsOld;

};


#endif //INC_3__FLYABLE_VEHICLE_H
