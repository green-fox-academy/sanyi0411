//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_2__ANIMALS_IN_THE_ZOO_MAMMAL_H
#define INC_2__ANIMALS_IN_THE_ZOO_MAMMAL_H

#include <iostream>
#include "Animal.h"

class Mammal : public Animal {
public:
    Mammal(std::string name);

    std::string getName();
    std::string breed();
};


#endif //INC_2__ANIMALS_IN_THE_ZOO_MAMMAL_H
