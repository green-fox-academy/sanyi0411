//
// Created by sando on 2019. 04. 23..
//

#ifndef INC_1__GREEN_FOX_ORGANIZATION_SPONSOR_H
#define INC_1__GREEN_FOX_ORGANIZATION_SPONSOR_H


#include "Person.h"
#include <iostream>

class Sponsor : public Person{
public:
    Sponsor();
    Sponsor(std::string name, int age, Gender gender, std::string company);

    void getGoal() override ;
    void introduce() override ;
    void hire();
private:
    std::string _company;
    int _hiredStudents;
};


#endif //INC_1__GREEN_FOX_ORGANIZATION_SPONSOR_H
