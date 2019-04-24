//
// Created by sando on 2019. 04. 23..
//

#ifndef INC_1__GREEN_FOX_ORGANIZATION_PERSON_H
#define INC_1__GREEN_FOX_ORGANIZATION_PERSON_H

#include <iostream>

enum Gender {
    MALE,
    FEMALE
};

class Person {
public:
    Person();
    Person(std::string name, int age, Gender gender);

    virtual void introduce ();
    virtual void getGoal();

    const std::string &getName() const;
    int getAge() const;

    std::string genderToString();
private:
    std::string _name;
    int _age;
    Gender _gender;

};


#endif //INC_1__GREEN_FOX_ORGANIZATION_PERSON_H
