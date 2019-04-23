//
// Created by sando on 2019. 04. 23..
//

#ifndef INC_3__AIRCRAFT_CARRIER_CARRIER_H
#define INC_3__AIRCRAFT_CARRIER_CARRIER_H

#include "Aircraft.h"
#include <vector>


class Carrier {
public:
    Carrier(int ammoOnBoard, int health, std::string name);

    void addAircraft(Aircraft aircraft);
    void fillAllAircrafts();

private:
    std::vector<Aircraft> _aircrafts;
    int _ammoOnBoard;
    int _health;
    std::string _name;
};


#endif //INC_3__AIRCRAFT_CARRIER_CARRIER_H
