//
// Created by sando on 2019. 04. 23..
//

#ifndef INC_1__GREEN_FOX_ORGANIZATION_MENTOR_H
#define INC_1__GREEN_FOX_ORGANIZATION_MENTOR_H

#include "Person.h"
#include <iostream>

enum Level {
    JUNIOR,
    INTERMEDIATE,
    SENIOR
};

class Mentor : public Person {
public:
    Mentor();
    Mentor(std::string name, int age, Gender gender, Level level);

    void getGoal() override;
    void introduce() override;
    std::string levelToString();
private:
    Level _level;
};


#endif //INC_1__GREEN_FOX_ORGANIZATION_MENTOR_H
