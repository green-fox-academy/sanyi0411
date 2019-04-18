#include <iostream>
#include "Sharpie.h"
#include "SharpieSet.h"

std::vector<Sharpie> initializeSharpieSet ()
{
    std::vector<Sharpie> sharpies;

    sharpies.push_back(Sharpie ("blue_thick", 1, 5));
    sharpies.push_back(Sharpie ("green", 0.5, 2));
    sharpies.push_back(Sharpie ("black", 0.7, 0));
    sharpies.push_back(Sharpie ("blue_thin", 0.5, 0)),
    sharpies.push_back(Sharpie ("red", 0.7, 3));

    return sharpies;
}

int main()
{
    SharpieSet mySharpies (initializeSharpieSet());

    std::cout << "You have " << mySharpies.countUsable() << " usable sharpies left\n\n";

    mySharpies.removeTrash();
    std::cout << "After removing the trash, you have these sharpies left: \n";
    mySharpies.print();


    return 0;
}