//
// Created by sando on 2019. 04. 23..
//

#include "Garden.h"

Garden::Garden()
{}

void Garden::addFlower(Flower flower)
{
    _flowers.push_back(flower);
}

void Garden::addTree(Tree tree)
{
    _trees.push_back(tree);
}

void Garden::watering (int waterAmount)
{
    std::cout << "Watering with " << waterAmount << std::endl;

    int needsWater = 0;
    for (int i = 0; i < _flowers.size(); i++) {
        if(!_flowers[i].enoughWater()) {
            needsWater++;
        }
    }
    for (int i = 0; i < _trees.size(); i++) {
        if(!_trees[i].enoughWater()) {
            needsWater++;
        }
    }

    float individualWater = waterAmount / needsWater;
    for (int i = 0; i < _flowers.size(); i++) {
        if(!_flowers[i].enoughWater()) {
            _flowers[i].setHasWater(_flowers[i].getHasWater() + (individualWater * 0.75));
        }
    }
    for (int i = 0; i < _trees.size(); i++) {
        if(!_trees[i].enoughWater()) {
            _trees[i].setHasWater(_trees[i].getHasWater() + (individualWater * 0.4));
        }
    }
    Garden::info();
}

void Garden::info()
{
    for (int i = 0; i < _flowers.size(); i++) {
        _flowers[i].info();
    }
    for (int j = 0; j < _trees.size(); j++) {
        _trees[j].info();
    }
    std::cout << std::endl;
}