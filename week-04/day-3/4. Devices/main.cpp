#include <iostream>
#include <vector>
#include "Printer.h"
#include "Printer2D.h"
#include "Printer3D.h"
#include "Copier.h"

int main(int argc, char *args[])
{
    // Create a vector that holds Printer* objects
    // Fill the vector with 3 Printer2D, 2 Printer3D and 1 copier.
    // Iterate through the vector and invoke print function on all of them.

    // Create a vector that holds Scanner* objects
    // Fill the vector with 2 Scanner and 2 Copier objects.
    // Iterate through the vector and invoke scan function on all of them

    // Create a Copier object and invoke copy function on it.

    std::vector<Printer*> printers;

    Printer2D lucy2D(2, 2);
    Printer2D sam2D(3, 3);
    Printer2D mary2D(3, 4);

    Printer3D bob3D(5, 5, 5);
    Printer3D susan3D(6, 5, 6);

    Copier carolCopier(6, 6, 100);

    printers.push_back(&lucy2D);
    printers.push_back(&sam2D);
    printers.push_back(&mary2D);
    printers.push_back(&bob3D);
    printers.push_back(&susan3D);
    printers.push_back(&carolCopier);

    for (int i = 0; i < printers.size(); ++i) {
        printers[i]->print();
    }

    std::vector<Scanner*> scanners;

    Scanner sarahScanner(100);
    Scanner sophiaScanner(150);

    Copier carmenCopier(5, 6, 120);

    scanners.push_back(&sarahScanner);
    scanners.push_back(&sophiaScanner);
    scanners.push_back(&carmenCopier);
    scanners.push_back(&carolCopier);

    for (int j = 0; j < scanners.size(); ++j) {
        scanners[j]->scan();
    }

    carolCopier.copy();

    return 0;
}