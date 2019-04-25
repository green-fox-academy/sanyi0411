//
// Created by sando on 2019. 04. 25..
//

#include "gtest/gtest.h"
#include "Fibonacci.h"

TEST(fibonacciTest, testNegativeNumber)
{
    Fibonacci fibNum;
    ASSERT_ANY_THROW(
        fibNum.fibonacci(-1);
    );
}

TEST(fibonacciTest, test20thNumber)
{
    Fibonacci fibNum;
    int value = fibNum.fibonacci(20);
    ASSERT_EQ(value, 6765);
}

TEST(fibonacciTest, test30thNumber)
{
    Fibonacci fibNum;
    int value = fibNum.fibonacci(30);
    ASSERT_EQ(value, 832040);
}