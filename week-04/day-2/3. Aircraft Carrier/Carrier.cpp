//
// Created by sando on 2019. 04. 23..
//

#include "Carrier.h"

Carrier::Carrier(int carrierAmmo, int carrierHealth, std::string carrierName)
{
    _carrierAmmo = carrierAmmo;
    _carrierHealth = carrierHealth;
    _carrierName = carrierName;
}

void Carrier::addAircraft(Aircraft aircraft)
{
    _aircrafts.push_back(aircraft);
}

void Carrier::fillAllAircrafts()
{
    if(_carrierAmmo > 0) {
        for (int i = 0; i < _aircrafts.size(); i++) {
            if (_aircrafts[i].getType() == "F35") {
                if (_carrierAmmo - (12 - _aircrafts[i].getAmmunition()) > 0) {
                    _carrierAmmo -= (12 - _aircrafts[i].getAmmunition());
                    _aircrafts[i].setAmmunition(12);
                } else {

                }
            }
        }
    } else {
        throw 123;
    }
}