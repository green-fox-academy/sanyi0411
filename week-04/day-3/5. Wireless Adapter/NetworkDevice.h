//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_5__WIRELESS_ADAPTER_NETWORKDEVICE_H
#define INC_5__WIRELESS_ADAPTER_NETWORKDEVICE_H

#include "Device.h"

class NetworkDevice : public virtual Device {
public:
    NetworkDevice(std::string id, int bandwidth);

    int getBandwidth();

private:
    int _bandwidth;
};


#endif //INC_5__WIRELESS_ADAPTER_NETWORKDEVICE_H
