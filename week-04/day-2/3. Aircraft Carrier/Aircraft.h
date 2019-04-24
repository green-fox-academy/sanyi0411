//
// Created by sando on 2019. 04. 23..
//

#ifndef INC_3__AIRCRAFT_CARRIER_AIRCRAFT_H
#define INC_3__AIRCRAFT_CARRIER_AIRCRAFT_H

#include <iostream>

enum Type {
    F16,
    F35
};

class Aircraft {
public:
    Aircraft (Type type);

    std::string getType();
    int getAmmunition();
    std::string getStatus();
    void setAmmunition(int a);

    int baseDamage ();
    int maxAmmo();
    int flight();
    int refill(int ammo);
    bool isPriority();

private:
    Type _type;
    int _ammunition;
};


#endif //INC_3__AIRCRAFT_CARRIER_AIRCRAFT_H
