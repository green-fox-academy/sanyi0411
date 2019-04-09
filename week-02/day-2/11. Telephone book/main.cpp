#include <iostream>
#include <string>
#include <map>

int main() {

    std::map<std::string, std::string> tel = {{"William A. Lathan", "405-709-1865"},
                                              {"John K. Miller", "402-247-8568"},
                                              {"Hortensia E. Foster", "606-481-6467"},
                                              {"Amanda D. Newland", "319-243-5613"},
                                              {"Brooke P. Askew", "307-687-2982"}};

    //What is John K. Miller's phone number?
    std::cout << "John K. Miller's phone#: " << tel["John K. Miller"] << std::endl;

    //Whose phone number is 307-687-2982?
    std::map<std::string, std::string>::iterator it;
    for (it = tel.begin(); it != tel.end(); it++) {
        if (it->second.compare("307-687-2982") == 0) {
            std::cout << it->first << std::endl;
        }
    }

    //Do we know Chris E. Myers' phone number?
    if (tel.count("Chris E. Myers") == 1) {
        std::cout << "We have Chris' number";
    } else {
        std::cout << "We don't have Chris' number";
    }

    return 0;
}