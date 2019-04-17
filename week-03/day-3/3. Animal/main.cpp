#include <iostream>
#include "Animal.h"

int main()
{

    Animal dog;
    dog.play();
    std::cout << "Dog's hunger: " << dog.getHunger() << std::endl <<
        "Dog's thirst: " << dog.getThirst() << std::endl;

    Animal cat;
    cat.drink();
    std::cout << "Cat's thirst: " << cat.getThirst() << std::endl;

    Animal lion;
    lion.eat();
    std::cout << "Lion's hunger: " << lion.getHunger() <<std::endl;

    return 0;
}