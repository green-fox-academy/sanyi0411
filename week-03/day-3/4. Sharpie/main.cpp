#include <iostream>
#include "Sharpie.h"

int main()
{
    Sharpie mySharpie ("blue", 1);
    mySharpie.use();

    std::cout << "Sharpie color: " << mySharpie.getColor() << std::endl <<
        "Sharpie width: " << mySharpie.getWidth() << std::endl <<
        "Sharpie ink amount: " << mySharpie.getInkAmount() << std::endl;

    return 0;
}