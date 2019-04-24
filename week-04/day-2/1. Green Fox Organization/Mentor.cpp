//
// Created by sando on 2019. 04. 23..
//

#include "Mentor.h"

Mentor::Mentor() : Person()
{
    _level = INTERMEDIATE;
}

Mentor::Mentor(std::string name, int age, Gender gender, Level level) : Person (name, age, gender)
{
    _level = level;
}

void Mentor::getGoal ()
{
    std::cout << "My goal is: Educate brilliant junior software developers.\n";
}

void Mentor::introduce ()
{
    std::cout << "Hi, I'm " << getName() << ", a " << getAge() << " year old " << genderToString() << ", " <<
        levelToString() << " mentor\n";
}

std::string Mentor::levelToString()
{
    switch(_level) {
        case JUNIOR:
            return "junior";
        case INTERMEDIATE:
            return "intermediate";
        case SENIOR:
            return "senior";
        default:
            return "";
    }
}
