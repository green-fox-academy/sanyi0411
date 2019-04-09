#include <iostream>
#include <string>
#include <vector>
int main() {

    //Create an empty list which will contain names (strings)
    std::vector<std::string> list;

    //Print out the number of elements in the list
    std::cout << "The size of the list is " << list.size() << std::endl;

    //Add William to the list
    list.push_back("William");

    //Print out whether the list is empty or not
    if (list.empty()) {
        std::cout << "List is empty!\n";
    } else {
        std::cout << "List is NOT empty!\n";
    }

    //Add John to the list
    list.push_back("John");

    //Add Amanda to the list
    list.push_back("Amanda");

    //Print out the number of elements in the list
    std::cout << "The size of the list is " << list.size() << std::endl;

    //Print out the 3rd element
    std::cout << "The 3rd element of the list is " << list[2] << std::endl;

    //Iterate through the list and print out each name
    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << std::endl;
    }

    //Iterate through the list and print
    for (int i = 0; i < list.size(); i++) {
        std::cout << i + 1 << ". " << list[i] << std::endl;
    }

    //Remove the 2nd element
    list.erase (list.begin() + 1);

    //Iterate through the list in a reversed order and print out each name
    for (int i = list.size(); i >= 0; i--) {
        std::cout << list[i] << std::endl;
    }


    return 0;
}