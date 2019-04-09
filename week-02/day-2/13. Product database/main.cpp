#include <iostream>
#include <string>
#include <map>
#include <vector>


int main() {

    std::map<std::string, int> products = {{"eggs", 200},
                                           {"milk", 200},
                                           {"fish", 400},
                                           {"apples", 150},
                                           {"bread", 50},
                                           {"chicken", 550}};

    //How much is the fish?
    std::cout << "Price of fish: " << products["fish"] << std::endl;

    //What is the most expensive product?
    std::string exp = "";
    int pri = 0;
    std::map<std::string, int>::iterator it;
    for (it = products.begin(); it != products.end(); it++) {
        if (pri < it->second) {
            pri = it->second;
            exp = it->first;
        }
    }
    std::cout << "The most expensive product is: " << exp <<std::endl;

    //What is the average price?
    float sum = 0.0;
    for (it = products.begin(); it != products.end(); it++) {
        sum += it->second;
    }
    float ave = sum / products.size();
    std::cout << "The average price is: " << ave << std::endl;

    //How many products' price is below 300?
    std::vector<char> count;
    for (it = products.begin(); it != products.end(); it++) {
        if (it->second < 300) {
            count.push_back('a');
        }
    }
    std::cout << "There are " << count.size() << " products under 300." << std::endl;

    //Is there anything we can buy for exactly 125?
    int there = 0;
    for (it = products.begin(); it != products.end(); it++) {
        if (it->second == 125) {
            there++;
        }
    }
    if (there > 0) {
        std::cout << "There are " << there << " product you can buy for exactly 125\n";
    } else {
        std::cout << "There is no product for exactly 125\n";
    }

    //What is the cheapest product?
    std::string cheap = "";
    int low = pri;
    for (it = products.begin(); it != products.end(); it++) {
        if (pri > it->second) {
            pri = it->second;
            cheap = it->first;
        }
    }
    std::cout << "The cheapest product is: " << cheap <<std::endl;

    return 0;
}
