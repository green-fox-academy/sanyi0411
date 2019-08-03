#include <iostream>
#include "SerialPort.h"
#include "opencv2/highgui.hpp"

int main(int argc, char** argv)
{
    std::string portName = "\\\\.\\COM7";
    SerialPort *car;
    car = new SerialPort(portName.c_str());
    bool connected = car->isConnected();
    std::cout << "Is connected: " << std::boolalpha << car->isConnected() << std::endl;
    std::string command = "motor forward 50 1\n";
    std::cout << "Data transfer: " << std::boolalpha << car->writeSerialPort(command.c_str(), 20) << std::endl;

    return 0;
}