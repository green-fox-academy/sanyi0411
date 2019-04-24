//
// Created by sando on 2019. 04. 23..
//

#include "Person.h"

Person::Person()
{
    _name = "Jane Doe";
    _age = 30;
    _gender = FEMALE;
}

Person::Person(std::string name, int age, Gender gender)
{
    _name = name;
    _age = age;
    _gender = gender;
}

void Person::introduce()
{
    std::cout << "Hi, my name is " << _name << ", a " << _age << " year old " << genderToString() << std::endl;
}

void Person::getGoal()
{
    std::cout << "My goal is: Live for the moment!\n";
}

std::string Person::genderToString()
{
    if (_gender == MALE) {
        return "male";
    } else {
        return "female";
    }
}

const std::string &Person::getName() const
{
    return _name;
}

int Person::getAge() const
{
    return _age;
}
