cmake_minimum_required(VERSION 3.13)
project(5__Wireless_Adapter)

set(CMAKE_CXX_STANDARD 14)

add_executable(5__Wireless_Adapter main.cpp Device.cpp Device.h USBDevice.cpp USBDevice.h NetworkDevice.cpp NetworkDevice.h WirelessAdapter.cpp WirelessAdapter.h)