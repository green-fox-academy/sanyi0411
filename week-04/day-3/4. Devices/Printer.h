//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_4__DEVICES_PRINTER_H
#define INC_4__DEVICES_PRINTER_H

#include <iostream>

class Printer {
public:
    virtual std::string getSize() = 0;
    void print();

};


#endif //INC_4__DEVICES_PRINTER_H
