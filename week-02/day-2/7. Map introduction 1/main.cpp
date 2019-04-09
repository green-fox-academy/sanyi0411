#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {

    //Create an empty map where the keys are integers and the values are characters
    std::map<int, char> myMap;

    //Print out whether the map is empty or not
    if (myMap.empty()) {
        std::cout << "The map is empty.\n";
    } else {
        std::cout << "The map is not empty.\n";
    }

    //Add the following key-value pairs to the map
    myMap[97] = 'a';
    myMap[98] = 'b';
    myMap[99] = 'c';
    myMap[65] = 'A';
    myMap[66] = 'B';
    myMap[67] = 'C';

    //Print all the keys
    std::map<int, char>::iterator myMapIteratorKeys;
    for (myMapIteratorKeys = myMap.begin(); myMapIteratorKeys != myMap.end(); myMapIteratorKeys++) {
        std::cout << myMapIteratorKeys->first << "\t";
    }
    std::cout << std::endl;

    //Print all the values
    std::map<int, char>::iterator myMapIteratorValues;
    for (myMapIteratorValues = myMap.begin(); myMapIteratorValues != myMap.end(); myMapIteratorValues++) {
        std::cout << myMapIteratorValues->second << "\t";
    }
    std::cout << std::endl;

    //Add value D with the key 68
    myMap[68] = 'D';

    //Print how many key-value pairs are in the map
    std::cout << "size of the map: " << myMap.size() << std::endl;

    //Print the value that is associated with key 99
    std::cout << myMap[99] << std::endl;

    //Remove the key-value pair where with key 97
    myMap.erase(97);

    //Print whether there is an associated value with key 100 or not
    if (myMap.count(100) == 1) {
        std::cout << "There is a value associated to key 100.\n";
    } else {
        std::cout << "There is not such key.\n";
    }

    //Remove all the key-value pairs
    myMap.clear();

    return 0;
}