//
// Created by sando on 2019. 04. 18..
//

#ifndef INC_11__SHARPIE_SET_SHARPIESET_H
#define INC_11__SHARPIE_SET_SHARPIESET_H

#include "Sharpie.h"
#include <iostream>
#include <vector>

class SharpieSet {
public:
    SharpieSet (std::vector<Sharpie> sharpie);

    int countUsable ();

    void removeTrash ();

    void print ();

private:
    std::vector<Sharpie> _sharpie;
};

#endif //INC_11__SHARPIE_SET_SHARPIESET_H
