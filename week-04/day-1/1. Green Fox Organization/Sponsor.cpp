//
// Created by sando on 2019. 04. 23..
//

#include "Sponsor.h"

Sponsor::Sponsor() : Person()
{
    _company = "Google";
    _hiredStudents = 0;
}

Sponsor::Sponsor(std::string name, int age, Gender gender, std::string company) : Person(name, age, gender)
{
    _hiredStudents = 0;
    _company = company;
}

void Sponsor::getGoal()
{
    std::cout << "My goal is: Hire brilliant junior software developers.\n";
}

void Sponsor::introduce()
{
    std::cout << "Hi, I'm " << getName() << ", a " << getAge() << "year old " << genderToString() << " who represents "
        << _company << " and hired " << _hiredStudents << " students so far.\n";
}

void Sponsor::hire()
{
    _hiredStudents++;
}