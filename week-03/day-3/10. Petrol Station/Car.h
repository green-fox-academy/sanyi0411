//
// Created by sando on 2019. 04. 17..
//

#ifndef INC_10__PETROL_STATION_CAR_H
#define INC_10__PETROL_STATION_CAR_H
#include <iostream>

class Car {
public:
    Car (int capacity, int gasAmount);

    int getCapacity();
    int getGasAmount();

    void setCapacity(int capacity);
    void setGasAmount(int gasAmount);

    bool isFull();
    void fill();

private:
    int _capacity;
    int _gasAmount;
};


#endif //INC_10__PETROL_STATION_CAR_H
