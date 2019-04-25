//
// Created by sando on 2019. 04. 25..
//

#include "Anagram.h"
#include "gtest/gtest.h"

TEST(anagramTest, testIsAnagram)
{
    Anagram anagram;
    bool output = anagram.isAnagram("listen", "silent");
    ASSERT_EQ(output, true);
}

TEST(anagramTest, testNotAnagram)
{
    Anagram anagram;
    bool output = anagram.isAnagram("doggo", "kitten");
    ASSERT_EQ(output, false);
}