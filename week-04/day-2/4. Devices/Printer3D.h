//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_4__DEVICES_PRINTER3D_H
#define INC_4__DEVICES_PRINTER3D_H

#include <iostream>
#include "Printer.h"

class Printer3D : public Printer {
public:
    Printer3D(int sizeX, int sizeY, int sizeZ);
    std::string getSize();

protected:
    int _sizeX;
    int _sizeY;
    int _sizeZ;

};


#endif //INC_4__DEVICES_PRINTER3D_H
