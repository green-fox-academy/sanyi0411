//
// Created by sando on 2019. 04. 25..
//
#include "gtest/gtest.h"
#include "CountLetters.h"

TEST(countLettersTest, testShortWord)
{
    //Arrange
    std::map<char, int> output;
    CountLetters word;

    //Act
    output = word.dictionaryOfLetters("apple");

    //Assert
    ASSERT_EQ(output['a'], 1);
    ASSERT_EQ(output['p'], 2);
    ASSERT_EQ(output['l'], 1);
    ASSERT_EQ(output['e'], 1);
}

TEST(countLettersTest, testLongWord)
{
    //Arrange
    std::map<char, int> output;
    CountLetters word;

    //Act
    output = word.dictionaryOfLetters("ItTakesTooLoOoOng");

    //Assert
    ASSERT_EQ(output['I'], 1);
    ASSERT_EQ(output['T'], 2);
    ASSERT_EQ(output['a'], 1);
    ASSERT_EQ(output['k'], 1);
    ASSERT_EQ(output['e'], 1);
    ASSERT_EQ(output['o'], 4);
    ASSERT_EQ(output['L'], 1);
    ASSERT_EQ(output['O'], 2);
    ASSERT_EQ(output['n'], 1);
    ASSERT_EQ(output['g'], 1);
}