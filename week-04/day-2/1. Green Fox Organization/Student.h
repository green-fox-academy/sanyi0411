//
// Created by sando on 2019. 04. 23..
//

#ifndef INC_1__GREEN_FOX_ORGANIZATION_STUDENT_H
#define INC_1__GREEN_FOX_ORGANIZATION_STUDENT_H

#include "Person.h"
#include <iostream>

class Student : public Person {
public:
    Student();
    Student (std::string name, int age, Gender gender, std::string previousOrganization);

    void getGoal() override;
    void introduce() override;
    void skipDays(int numberOfDays);
private:
    std::string _previousOrganization;
    int _skippedDays;
};


#endif //INC_1__GREEN_FOX_ORGANIZATION_STUDENT_H
