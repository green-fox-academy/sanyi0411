//
// Created by sando on 2019. 04. 17..
//

#include "Fleet.h"

Fleet::Fleet() {}

void Fleet::add(const Thing& thing)
{
    things.push_back(thing);
}

std::string Fleet::toString()
{
    std::string result = "";
    for(int i = 0; i < things.size(); i++) {
        result += std::to_string(i+1) + ". " + things.at(i).toString() + "\n";
    }
    return result;
}