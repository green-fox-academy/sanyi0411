//
// Created by sando on 2019. 04. 24..
//

#include "Apple.h"

std::string Apple::getApple()
{
    return "apple";
}

int Apple::getSum(std::vector<int>numbers, int size)
{
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += numbers[i];
    }
    return sum;
}