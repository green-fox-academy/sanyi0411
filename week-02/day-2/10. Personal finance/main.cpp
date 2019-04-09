#include <iostream>
#include <vector>

int spent (std::vector<int>);

int greatest (std::vector<int>);

int cheapest (std::vector<int>);

double average (std::vector<int>);

int main() {

    std::vector<int> expenses = {500, 1000, 1250, 175, 800, 120};

    std::cout << "Total spending: " << spent(expenses) << std::endl;

    std::cout << "Greatest expense was: " << greatest(expenses) << std::endl;

    std::cout << "Cheapest spending was: " << cheapest(expenses) << std::endl;

    std::cout << "The average of out spending was: " << average(expenses) << std::endl;

    return 0;
}

int spent (std::vector<int> input) {
    int sum = 0;
    for (int i = 0; i < input.size(); i++) {
        sum += input[i];
    }
    return sum;
}

int greatest (std::vector<int> input) {
    int max = input[0];
    for (int i = 1; i < input.size(); i++) {
        if (max < input[i]){
            max = input[i];
        }
    }
    return max;
}

int cheapest (std::vector<int> input) {
    int min = input[0];
    for (int i = 1; i < input.size(); i++) {
        if (min > input[i]){
            min = input[i];
        }
    }
    return min;
}

double average (std::vector<int> input) {
    double sum = 0.0;
    for (int i = 0; i < input.size(); i++) {
        sum += input[i];
    }
    double ave = sum / (input.size());
    return ave;
}