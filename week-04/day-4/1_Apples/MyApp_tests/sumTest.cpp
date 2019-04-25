//
// Created by sando on 2019. 04. 25..
//
#include "Apple.h"
#include "gtest/gtest.h"

TEST(sumTest, testSumMultipleElements)
{
    //Arrange
    std::vector<int> input;
    for (int i = 0; i < 5; ++i) {
        input.push_back(i);
    }
    int size = input.size();

    //Act
    Apple sum;
    int output = sum.getSum(input, size);

    //Assert
    ASSERT_EQ(output, 10);
}

TEST(sumTest, testSumEmptyVector)
{
    std::vector<int> input;
    int size = input.size();

    Apple sum;
    int output = sum.getSum(input, size);

    ASSERT_EQ(output, 0);
}

TEST(sumTest, testSumOneElement)
{
    std::vector<int> input;
    input.push_back(5);
    int size = input.size();

    Apple sum;
    int output = sum.getSum(input, size);

    ASSERT_EQ(output, 5);
}

TEST(sumTest, testSumNegative)
{
    std::vector<int> input;
    input.push_back(-5);
    input.push_back(-6);
    input.push_back(-4);
    int size = input.size();

    Apple sum;
    int output = sum.getSum(input, size);

    ASSERT_EQ(output, -15);
}