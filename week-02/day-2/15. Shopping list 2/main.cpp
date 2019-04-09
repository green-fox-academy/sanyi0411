#include <iostream>
#include <vector>
#include <map>
#include <string>
/*
int pay (std::map<std::string, int>);

int main() {

    std::map<std::string, double> myList = {{"milk", 1.07},
                                            {"rice", 1.59},
                                            {"eggs", 3.14},
                                            {"cheese", 12.60},
                                            {"chicken breasts", 9.40},
                                            {"apples", 2.31},
                                            {"tomato", 2.58},
                                            {"potato", 1.75},
                                            {"onion", 1.10}};

    std::map<std::string, int> bobList = {{"milk", 3},
                                          {"rice", 2},
                                          {"eggs", 2},
                                          {"cheese", 1},
                                          {"chicken breasts", 4},
                                          {"apples", 1},
                                          {"tomato", 2},
                                          {"potato", 1}};

    std::map<std::string, int> aliceList = {{"rice", 1},
                                            {"eggs", 5},
                                            {"chicken breasts", 2},
                                            {"apples", 1},
                                            {"tomato", 10}};

    //How much does Bob pay?
    std::cout << "Bob pays: " << pay(bobList) << std::endl;

    //How much does Alice pay?
    std::cout << "Alice pays: " << pay(aliceList) << std::endl;

    //Who buys more Rice?
    std::string who = "Alice";
    if (myList["rice"] > bobList["rice"]) {
        if (myList["rice"] > aliceList["rice"]){
            who = "Me";
        }
    } else {
        if (bobList["rice"] > aliceList["rice"]) {
            who = "Bob";
        }
    }
    std::cout <<"Who buys more rice?: " << who << std::endl;

    //Who buys more Potato?
    who = "Alice";
    if (myList["potato"] > bobList["potato"]) {
        if (myList["potato"] > aliceList["potato"]){
            who = "Me";
        }
    } else {
        if (bobList["potato"] > aliceList["potato"]) {
            who = "Bob";
        }
    }
    std::cout <<"Who buys more potato?: " << who << std::endl;

    //Who buys more different products?
    who = "Alice";
    if (myList.size() > bobList.size()) {
        if (myList.size() > aliceList.size()){
            who = "Me";
        }
    } else {
        if (bobList.size() > aliceList.size()) {
            who = "Bob";
        }
    }
    std::cout <<"Who buys more different products?: " << who << std::endl;

    //Who buys more products? (piece)


    return 0;
}

int pay (std::map<std::string, int> map) {
    std::map<std::string, int>::iterator it;
    int sum = 0;
    for (it = map.begin(); it != map.end(); it++){
        sum += it->second;
    }
    return sum;
}
int piece (std::map<std::string, int> map) {
    std::map<std::string, int>::iterator it;
    int sum = 0;
    for (it = map.begin(); it != map.end(); it++){
        sum += it->second;
    }
    return sum;
}*/