//
// Created by sando on 2019. 04. 24..
//

#include "NetworkDevice.h"

NetworkDevice::NetworkDevice(std::string id, int bandwidth) : Device(id)
{
    _bandwidth = bandwidth;
}

int NetworkDevice::getBandwidth()
{
    return _bandwidth;
}
