#include <iostream>
#include <map>
#include <string>
#include <vector>
#define n 201
#define m 150

int main() {

    std::map<std::string, int> products = {{"eggs", 200},
                                           {"milk", 200},
                                           {"fish", 400},
                                           {"apples", 150},
                                           {"bread", 50},
                                           {"chicken", 550}};

    //Which products cost less than 201? (just the name)
    std::vector<std::string> less;
    std::map<std::string, int>::iterator it;
    for (it = products.begin(); it != products.end(); it++) {
        if (it->second < n) {
            less.push_back(it->first);
        }
    }
    if (less.size() > 0) {
        std::cout << "These products cost less than " << n << ":\n";
        for (int i = 0; i < less.size(); i++) {
            std::cout << less[i] << std::endl;
        }
    } else {
        std::cout << "There are no products under " << n << std::endl;
    }

    //Which products cost more than 150? (name + price)
    less.clear();
    std::vector<int> more_price;
    for (it = products.begin(); it != products.end(); it++) {
        if (it->second > m) {
            less.push_back(it->first);
            more_price.push_back(it->second);
        }
    }
    if (less.size() > 0) {
        std::cout << "These product cost more than " << m << ":\n";
        for (int i = 0; i < less.size(); i++) {
            std::cout << less[i] << "(price: " << more_price[i] << ")" << std::endl;
        }
    } else {
        std::cout << "There are no products over " << m << std::endl;
    }

    return 0;
}