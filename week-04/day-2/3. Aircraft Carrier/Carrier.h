//
// Created by sando on 2019. 04. 23..
//

#ifndef INC_3__AIRCRAFT_CARRIER_CARRIER_H
#define INC_3__AIRCRAFT_CARRIER_CARRIER_H

#include "Aircraft.h"
#include <vector>


class Carrier {
public:
    Carrier(int carrierAmmo, int carrierHealth, std::string carrierName);

    void addAircraft(Aircraft aircraft);
    void fillAllAircrafts();

private:
    std::vector<Aircraft> _aircrafts;
    int _carrierAmmo;
    int _carrierHealth;
    std::string _carrierName;
};


#endif //INC_3__AIRCRAFT_CARRIER_CARRIER_H
