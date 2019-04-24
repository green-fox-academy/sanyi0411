//
// Created by sando on 2019. 04. 23..
//

#ifndef INC_2__THE_GARDEN_APPLICATION_TREE_H
#define INC_2__THE_GARDEN_APPLICATION_TREE_H

#include <iostream>

class Tree {
public:
    Tree ();
    Tree (float hasWater, std::string name);
    bool enoughWater();
    float getHasWater() const;
    void setHasWater(float hasWater);
    void info();
private:
    float _hasWater = 0.0;
    std::string _name;
};


#endif //INC_2__THE_GARDEN_APPLICATION_TREE_H
