//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_2__ANIMALS_IN_THE_ZOO_ANIMAL_H
#define INC_2__ANIMALS_IN_THE_ZOO_ANIMAL_H

#include <iostream>

class Animal {
public:
    virtual std::string getName() = 0;
    virtual std::string breed() = 0;
    void feed();

protected:
    std::string _name;
    int age;
    std::string _gender;
    int _weight;
};


#endif //INC_2__ANIMALS_IN_THE_ZOO_ANIMAL_H
