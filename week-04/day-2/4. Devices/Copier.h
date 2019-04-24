//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_4__DEVICES_COPIER_H
#define INC_4__DEVICES_COPIER_H

#include "Printer2D.h"
#include "Scanner.h"

class Copier : public Printer2D, public Scanner {
public:
    Copier(int sizeX, int sizeY, int speed);

    void copy();
};


#endif //INC_4__DEVICES_COPIER_H
