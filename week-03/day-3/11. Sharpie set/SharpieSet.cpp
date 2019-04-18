//
// Created by sando on 2019. 04. 18..
//

#include "SharpieSet.h"

SharpieSet::SharpieSet (std::vector<Sharpie> sharpie)
{
    _sharpie = sharpie;
}

int SharpieSet::countUsable ()
{
    int count = 0;
    for (int i = 0; i < SharpieSet::_sharpie.size(); i++){
        if (SharpieSet::_sharpie[i].getInkAmount() > 0){
            count++;
        }
    }
    return count;
}

void SharpieSet::removeTrash ()
{
    for (int i = 0; i < SharpieSet::_sharpie.size(); i++) {
        if (SharpieSet::_sharpie[i].getInkAmount() == 0) {
            SharpieSet::_sharpie.erase(SharpieSet::_sharpie.begin()+i);
            i--;
        }
    }
}

void SharpieSet::print ()
{
    for (int i = 0; i < SharpieSet::_sharpie.size(); i++) {
        std::cout << _sharpie[i].getColor() << std::endl;
    }
}