#include <iostream>

int main(int argc, char* args[]) {

    // An average Green Fox attendee codes 6 hours daily
    // The semester is 17 weeks long
    //
    // Print how many hours is spent with coding in a semester by an attendee,
    // if the attendee only codes on workdays.
    //
    // Print the percentage of the coding hours in the semester if the average
    // working hours weekly is 52

    int daily = 6;
    int workdays = 5;
    int semester = 17;
    double total = semester * workdays * daily;
    double whw = 52;

    std::cout << "An average Green Fox attendee codes ";
    std::cout << total;
    std::cout << " hours during a semester\n";

    std::cout << "This is ";
    std::cout << (total / (17 * whw)) * 100;
    std::cout << "% of his/her working hours";

    return 0;
}