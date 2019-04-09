#include <iostream>
#include <string>
#include <map>

int main() {

    //Create a map where the keys are strings and the values are strings with the following initial values
    std::map<std::string, std::string> myMap = {{"978-1-60309-452-8", "A Letter to Jo"},
                                                {"978-1-60309-459-7", "Lupus"},
                                                {"978-1-60309-444-3", "Red Panda and Moon Bear"},
                                                {"978-1-60309-461-0", "The Lab"}};

    //Print all the key-value pairs in the following format
    std::map<std::string, std::string>::iterator myMap_it;
    for (myMap_it = myMap.begin(); myMap_it != myMap.end(); myMap_it++) {
        std::cout << myMap_it->second << " (ISBN: " << myMap_it->first << ")" << std::endl;
    }
    std::cout << std::endl;

    //Remove the key-value pair with key 978-1-60309-444-3
    myMap.erase("978-1-60309-444-3");

    //Remove the key-value pair with value The Lab
    for (myMap_it = myMap.begin(); myMap_it != myMap.end(); myMap_it++) {
        if (myMap_it->second.compare("The Lab") == 0) {
            myMap.erase(myMap_it);
        }
    }

    //Add the following key-value pairs to the map
    myMap["978-1-60309-450-4"] = "They Calles Us Enemy";
    myMap["978-1-60309-453-5"] = "Why Did We Trust Him?";

    //Print whether there is an associated value with key 478-0-61159-424-8 or not
    if (myMap.count("478-0-61159-424-8") == 1) {
        std::cout << "There is a value associated to key 478-0-61159-424-8.\n\n";
    } else {
        std::cout << "There is not such key.\n\n";
    }

    //Print the value associated with key 978-1-60309-453-5
    std::cout << "The value associated to key 978-1-60309-453-5: " << myMap["978-1-60309-453-5"] << std::endl;

    return 0;
}