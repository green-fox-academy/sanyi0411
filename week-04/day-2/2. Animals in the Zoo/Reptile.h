//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_2__ANIMALS_IN_THE_ZOO_REPTILE_H
#define INC_2__ANIMALS_IN_THE_ZOO_REPTILE_H

#include <iostream>
#include "Animal.h"

class Reptile : public Animal {
public:
    Reptile(std::string name);
    std::string getName();
    std::string breed();
};


#endif //INC_2__ANIMALS_IN_THE_ZOO_REPTILE_H
