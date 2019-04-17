//
// Created by sando on 2019. 04. 17..
//

#ifndef INC_7__FLEET_OF_THINGS_FLEET_H
#define INC_7__FLEET_OF_THINGS_FLEET_H

#include <vector>
#include <string>

#include "thing.h"

class Fleet
{
public:
    Fleet();

    void add(const Thing& thing);
    std::string toString();

private:
    std::vector<Thing> things;
};


#endif //INC_7__FLEET_OF_THINGS_FLEET_H
