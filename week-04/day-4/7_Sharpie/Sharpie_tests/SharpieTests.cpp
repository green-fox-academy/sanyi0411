//
// Created by sando on 2019. 04. 25..
//

#include "gtest/gtest.h"
#include "Sharpie.h"

    //Create tests that covers all types of input (like in the previous workshop exercise)
    //This time you test a class, you should make a test fixture for that.

class SharpieTest : public ::testing::Test
{
protected:
    void SetUp() override {
        _sharpie.setInkAmount(100);
    }
    void TearDown() override{};

    Sharpie _sharpie;
};

TEST_F(SharpieTest, testUseOnce)
{
    //Act
    _sharpie.use();

    //Assert
    ASSERT_EQ(_sharpie.getInkAmount(), 95);
}

TEST_F(SharpieTest, testUseThreeTimes)
{
    //Act
    _sharpie.use();
    _sharpie.use();
    _sharpie.use();

    //Assert
    ASSERT_EQ(_sharpie.getInkAmount(), 85);
}

TEST_F(SharpieTest, testColor)
{
    //Arrange
    std::string color = "blue";

    //Act
    _sharpie.setColor(color);

    //Assert
    ASSERT_EQ(_sharpie.getColor(), "blue");
}