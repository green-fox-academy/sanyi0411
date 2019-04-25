//
// Created by sando on 2019. 04. 24..
//

#include "Apple.h"
#include "gtest/gtest.h"

TEST(appleTest, testOutputString)
{
    Apple apple;
    std::string output = apple.getApple();
    EXPECT_EQ (output, "apple");
}