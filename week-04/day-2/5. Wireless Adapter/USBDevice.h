//
// Created by sando on 2019. 04. 24..
//

#ifndef INC_5__WIRELESS_ADAPTER_USBDEVICE_H
#define INC_5__WIRELESS_ADAPTER_USBDEVICE_H

#include "Device.h"

enum USBType {
    USB_TYPE_2,
    USB_TYPE_3
};

class USBDevice : public virtual Device {
public:
    USBDevice(std::string id, USBType usbType);

    std::string getUsbType();

private:
    int _usbType;

};


#endif //INC_5__WIRELESS_ADAPTER_USBDEVICE_H
