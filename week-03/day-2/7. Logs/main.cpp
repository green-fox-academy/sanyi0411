#include <iostream>
#include <fstream>
#include <string>
#include <vector>

// Read all data from 'log.txt'.
// Each line represents a log message from a web server
// Write a function that returns an array with the unique IP adresses.
// Write a function that returns the GET / POST request ratio.

int countLines(std::string file);

void swap(std::string &a, std::string &b);

void bubbleSort(std::string arr[], int size);

std::vector<std::string> unique(std::string arr[], int size);

double ratio(std::string input[], int size);

int main()
{

    std::ifstream myFile;
    std::ofstream ipFile;
    myFile.exceptions(std::ifstream::badbit);
    ipFile.exceptions(std::ofstream::failbit | std::ofstream::badbit);
    int numberOfLines = countLines("../logs.txt");
    try {
        myFile.open("../logs.txt");
        ipFile.open("../unique_ip_addresses.txt");
        std::string logs[numberOfLines][8];

        for (int i = 0; i < numberOfLines; i++) {
            for (int j = 0; j < 8; j++) {
                myFile >> logs[i][j];
            }
        }

        std::string ipAddresses[numberOfLines];

        for (int i = 0; i < numberOfLines; i++) {
            ipAddresses[i] = logs[i][5];
        }

        int ipAddressesArraySize = sizeof(ipAddresses) / sizeof(ipAddresses[0]);

        bubbleSort(ipAddresses, ipAddressesArraySize);
        std::vector <std::string> temp =  unique(ipAddresses, ipAddressesArraySize);



        for (int i = 0; i < temp.size(); i++) {
            ipFile << temp[i] << std::endl;
        }

        std::string getPost[numberOfLines];

        for (int i = 0; i < numberOfLines; i++) {
            getPost[i] = logs[i][6];
        }

        int getPostArraySize = sizeof(getPost) / sizeof(getPost[0]);

        std::cout << "The GET / POST ratio: " << ratio(getPost, getPostArraySize) << std::endl;

        myFile.close();
        ipFile.close();

    } catch (std::ifstream::failure &e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

int countLines(std::string inputFile)
{
    std::ifstream myFile;
    myFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    int numberOfLines = 0;
    try {
        myFile.open(inputFile);
        while (!myFile.eof()) {
            std::string text;
            getline(myFile, text);
            numberOfLines++;
        }
    }
    catch (std::ofstream::failure &e) {
        std::cout << e.what() << std::endl;
    }

    myFile.close();

    return numberOfLines;
}

void swap(std::string &a, std::string &b)
{
    std::string s = a;
    a = b;
    b = s;
}

void bubbleSort(std::string arr[], int size)
{
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

std::vector<std::string> unique(std::string arr[], int size)
{
    std::vector<std::string> a;
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            a.push_back(arr[i]);
        }
    }
    a.push_back(arr[size - 1]);

    return a;
}

double ratio(std::string input[], int size)
{
    double get = 0.0;
    double post = 0.0;
    for (int i = 0; i < size; i++) {
        if (input[i] == "GET") {
            get++;
        } else {
            post++;
        }
    }
    return get/post;
}