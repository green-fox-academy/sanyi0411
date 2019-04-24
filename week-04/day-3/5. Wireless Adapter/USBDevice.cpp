//
// Created by sando on 2019. 04. 24..
//

#include "USBDevice.h"

USBDevice::USBDevice(std::string id, USBType usbType) : Device(id)
{
    _usbType = usbType;
}

std::string USBDevice::getUsbType()
{
    if(_usbType == 0) {
        return "USB Type 2";
    } else {
        return "USB Type 3";
    }
}
