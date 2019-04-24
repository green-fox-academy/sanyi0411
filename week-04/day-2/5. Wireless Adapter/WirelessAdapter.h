//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_5__WIRELESS_ADAPTER_WIRELESSADAPTER_H
#define INC_5__WIRELESS_ADAPTER_WIRELESSADAPTER_H

#include <iostream>
#include "USBDevice.h"
#include "NetworkDevice.h"

class WirelessAdapter : public USBDevice, public NetworkDevice {
public:
    WirelessAdapter(std::string id, USBType usbType, int bandwidth);
    void info();

};


#endif //INC_5__WIRELESS_ADAPTER_WIRELESSADAPTER_H
