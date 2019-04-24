//
// Created by sando on 2019. 04. 24..
//

#include "WirelessAdapter.h"

WirelessAdapter::WirelessAdapter(std::string id, USBType usbType, int bandwidth) : Device(id), USBDevice(id, usbType), NetworkDevice(id, bandwidth)
{}

void WirelessAdapter::info()
{
    std::cout << "ID: " << getID() << "\nUSB Type: " << getUsbType() << "\nBandwidth: " << getBandwidth() << std::endl;
}
