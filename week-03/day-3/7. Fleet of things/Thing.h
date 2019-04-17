//
// Created by sando on 2019. 04. 17..
//

#ifndef INC_7__FLEET_OF_THINGS_THING_H
#define INC_7__FLEET_OF_THINGS_THING_H

#include <string>

class Thing
{
public:
    Thing(const std::string& name);

    void complete();
    std::string toString();

private:
    std::string _name;
    bool _completed;
};


#endif //INC_7__FLEET_OF_THINGS_THING_H
