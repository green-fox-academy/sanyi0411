//
// Created by sando on 2019. 04. 23..
//

#ifndef INC_2__THE_GARDEN_APPLICATION_FLOWER_H
#define INC_2__THE_GARDEN_APPLICATION_FLOWER_H

#include <iostream>

class Flower {
public:
    Flower ();
    Flower (float hasWater, std::string name);
    bool enoughWater();
    void setHasWater(float hasWater);
    float getHasWater() const;
    void info();

private:
    float _hasWater = 0.0;
    std::string _name;
};


#endif //INC_2__THE_GARDEN_APPLICATION_FLOWER_H
