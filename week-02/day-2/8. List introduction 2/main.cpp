#include <iostream>
#include <vector>
#include <string>

int findDurian (std::vector<std::string>, std::string);

int main() {

    //Create a list ('List A') which contains the following values
    std::vector <std::string> List_A = {"Apple", "Avocado", "Blueberries", "Durian", "Lychee"};

    //Create a new list ('List B') with the values of List A
    std::vector <std::string> List_B = List_A;

    //Print out whether List A contains Durian or not
    if (findDurian(List_A, "Durian") != -1) {
        std::cout << "List contains Durian.\n\n";
    } else {
        std::cout << "List does not contain Durian.\n\n";
    }

    //Remove Durian from List B
    List_B.erase(List_B.begin() + (findDurian(List_A, "Durian")));

    //Add Kiwifruit to List A after the 4th element
    List_A.insert(List_A.begin() + 4, "Kiwifruit");

    std::cout << std::endl;

    //Compare the size of List A and List B
    if (List_A.size() > List_B.size()) {
        std::cout << "List A is bigger.\n\n";
    } else if (List_A.size() < List_B.size()) {
        std::cout << "List B is bigger.\n\n";
    } else {
        std::cout << "The two lists ara equal in size.\n\n";
    }

    //Get the index of Avocado from List A
    if (findDurian(List_A, "Avocado") != -1) {
        std::cout << "The index of Avocado in List A : " << findDurian(List_A, "Avocado") << std::endl << std::endl;
    } else {
        std::cout << "The list does not contain Avocado.";
    }

    //Get the index of Durian from List B
    if (findDurian(List_B, "Durian") != -1) {
        std::cout << "The index of Durian in List B : " << findDurian(List_B, "Durian") << std::endl << std::endl;
    } else {
        std::cout << "The list does not contain Durian.\n\n";
    }

    //Add Passion Fruit and Pummelo to List B in a single statement
    std::string a[2] = {"Passion Fruit", "Pumello"};
    List_B.insert(List_B.end(), a, a+2);

    //Print out the 3rd element from List A
    std::cout << List_A[2] << std::endl;

    return 0;
}

int findDurian (std::vector<std::string> vec, std::string input) {
    int index = -1;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == input) {
            index = i;
        }
    }
    return index;
}