//
// Created by sando on 2019. 04. 18..
//

#ifndef INC_12__FARM_ANIMAL_H
#define INC_12__FARM_ANIMAL_H

#include <iostream>

class Animal {
public:
    Animal (std::string name, int hunger, int thirst);

    int getHunger();
    int getThirst();
    std::string getName();

    void setHunger(int hunger);
    void setThirst(int thirst);
    void setName(std::string);

    void eat();
    void drink();
    void play();

private:
    std::string _name;
    int _hunger;
    int _thirst;

};


#endif //INC_12__FARM_ANIMAL_H
