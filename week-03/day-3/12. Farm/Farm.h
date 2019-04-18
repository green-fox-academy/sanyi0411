//
// Created by sando on 2019. 04. 18..
//

#ifndef INC_12__FARM_FARM_H
#define INC_12__FARM_FARM_H

#include <iostream>
#include <vector>
#include "Animal.h"


class Farm {
public:
    Farm(std::vector<Animal> animal, int maxAnimals);

    int freePlaces ();

    void breed(std::string name, int hunger, int thirst);

    void slaughter();

    void print ();

private:
    std::vector<Animal> _animal;
    int _maxAnimals;
};


#endif //INC_12__FARM_FARM_H
