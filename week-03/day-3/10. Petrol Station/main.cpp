#include <iostream>
#include "Station.h"
#include "Car.h"

int main()
{
    Station station (100);
    Car ford (7, 4);
    Car mazda (6, 4);
    Car opel (7, 5);
    Car citroen (5, 3);
    Car kia (6, 3);

    station.fillCar(ford);
    station.fillCar(mazda);
    station.fillCar(opel);
    station.fillCar(citroen);
    station.fillCar(kia);


    std::cout << "Ford: " << ford.getGasAmount() << "/" << ford.getCapacity() << std::endl;
    std::cout << "Mazda: " << mazda.getGasAmount() << "/" << mazda.getCapacity() << std::endl;
    std::cout << "Opel: " << opel.getGasAmount() << "/" << opel.getCapacity() << std::endl;
    std::cout << "Citroen: " << citroen.getGasAmount() << "/" << citroen.getCapacity() << std::endl;
    std::cout << "Kia: " << kia.getGasAmount() << "/" << kia.getCapacity() << std::endl;

    std::cout << "Station: " << station.getGasAmount() << "/100 left" << std::endl;

    return 0;
}