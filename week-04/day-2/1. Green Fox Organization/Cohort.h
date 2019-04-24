//
// Created by sando on 2019. 04. 23..
//

#ifndef INC_1__GREEN_FOX_ORGANIZATION_COHORT_H
#define INC_1__GREEN_FOX_ORGANIZATION_COHORT_H

#include "Student.h"
#include "Mentor.h"
#include <iostream>
#include <vector>

class Cohort {
public:
    Cohort(std::string name);

    void addStudent(Student *student);
    void addMentor(Mentor *mentor);
    void info();
private:
    std::string _name;
    std::vector<Student*> _students;
    std::vector<Mentor*> _mentors;
};


#endif //INC_1__GREEN_FOX_ORGANIZATION_COHORT_H
