//
// Created by sando on 2019. 04. 24..
//

#include "Device.h"

Device::Device(std::string id)
{
    _id = id;
}

std::string Device::getID()
{
    return _id;
}