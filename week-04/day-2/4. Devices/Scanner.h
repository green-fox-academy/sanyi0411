//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_4__DEVICES_SCANNER_H
#define INC_4__DEVICES_SCANNER_H

#include <iostream>

class Scanner {
public:
    Scanner(int speed);

    void scan();

protected:
    int _speed;
};


#endif //INC_4__DEVICES_SCANNER_H
