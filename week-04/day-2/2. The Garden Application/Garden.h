//
// Created by sando on 2019. 04. 23..
//

#ifndef INC_2__THE_GARDEN_APPLICATION_GARDEN_H
#define INC_2__THE_GARDEN_APPLICATION_GARDEN_H

#include <iostream>
#include <vector>
#include "Flower.h"
#include "Tree.h"

class Garden : public Flower, public Tree {
public:
    Garden ();
    void addFlower(Flower flower);
    void addTree(Tree tree);
    void watering(int waterAmount);
    void info();

private:
    std::vector<Flower> _flowers;
    std::vector<Tree> _trees;
};


#endif //INC_2__THE_GARDEN_APPLICATION_GARDEN_H
