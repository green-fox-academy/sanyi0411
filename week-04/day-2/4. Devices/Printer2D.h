//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_4__DEVICES_PRINTER2D_H
#define INC_4__DEVICES_PRINTER2D_H

#include <iostream>
#include "Printer.h"

class Printer2D : public Printer {
public:
    Printer2D(int sizeX, int sizeY);

    std::string getSize();

protected:
    int _sizeX;
    int _sizeY;

};


#endif //INC_4__DEVICES_PRINTER2D_H
