//
// Created by sando on 2019. 04. 23..
//

#include "Student.h"

Student::Student() : Person()
{
    _previousOrganization = "The School of Life";
    _skippedDays = 0;
}

Student::Student(std::string name, int age, Gender gender, std::string previousOrganization) : Person (name, age, gender)
{
    _skippedDays = 0;
}

void Student::getGoal()
{
    std::cout << "My goal is: Be a junior software developer.\n";
}

void Student::introduce()
{
    std::cout << "Hi, I'm " << getName() << ", a " << getAge() << " year old " << genderToString() << " from " <<
        _previousOrganization << " who skipped " << _skippedDays << " dys from the course already\n";
}

void Student::skipDays(int numberOfDays)
{
    _skippedDays += numberOfDays;
}