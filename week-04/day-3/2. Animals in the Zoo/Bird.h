//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_2__ANIMALS_IN_THE_ZOO_BIRD_H
#define INC_2__ANIMALS_IN_THE_ZOO_BIRD_H

#include <iostream>
#include "Animal.h"

class Bird : public Animal {
public:
    Bird(std::string name);

    std::string getName();
    std::string breed();

};


#endif //INC_2__ANIMALS_IN_THE_ZOO_BIRD_H
