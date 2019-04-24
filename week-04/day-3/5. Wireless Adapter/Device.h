//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_5__WIRELESS_ADAPTER_DEVICE_H
#define INC_5__WIRELESS_ADAPTER_DEVICE_H

#include <iostream>

class Device {
public:
    Device(std::string id);

    std::string getID();

private:
    std::string _id;

};


#endif //INC_5__WIRELESS_ADAPTER_DEVICE_H
