//
// Created by sando on 2019. 04. 17..
//

#ifndef INC_10__PETROL_STATION_STATION_H
#define INC_10__PETROL_STATION_STATION_H
#include <iostream>
#include "Car.h"


class Station {
public:
    Station (int gasAmount);

    void setGasAmount(int gasAmount);

    int getGasAmount();

    void fillCar(Car &current);

private:
    int _gasAmount;
};

#endif //INC_10__PETROL_STATION_STATION_H
