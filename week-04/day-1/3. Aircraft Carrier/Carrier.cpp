//
// Created by sando on 2019. 04. 23..
//

#include "Carrier.h"

Carrier::Carrier(int ammoOnBoard, int health, std::string name)
{
    _ammoOnBoard = ammoOnBoard;
    _health = health;
    _name = name;
}

void Carrier::addAircraft(Aircraft aircraft)
{
    _aircrafts.push_back(aircraft);
}

void Carrier::fillAllAircrafts()
{
    if(_ammoOnBoard > 0) {
        for (int i = 0; i < _aircrafts.size(); i++) {
            if (_aircrafts[i].getType() == "F35") {
                if (_ammoOnBoard - (12 - _aircrafts[i].getAmmunition()) > 0) {
                    _ammoOnBoard -= (12 - _aircrafts[i].getAmmunition());
                    _aircrafts[i].setAmmunition(12);
                } else {

                }
            }
        }
    } else {}
}