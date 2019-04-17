//
// Created by sando on 2019. 04. 17..
//

#ifndef INC_3__ANIMAL_ANIMAL_H
#define INC_3__ANIMAL_ANIMAL_H
#include <iostream>


class Animal {
public:
    Animal ();

    int getHunger();
    int getThirst();

    void setHunger(int hunger);
    void setThirst(int thirst);

    void eat();
    void drink();
    void play();

private:
    int _hunger;
    int _thirst;

};


#endif //INC_3__ANIMAL_ANIMAL_H
