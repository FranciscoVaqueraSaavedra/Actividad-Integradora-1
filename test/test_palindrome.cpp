//
// Created by Franc on 20/05/2025.
//

#include "palindrome.h"
#include <gtest/gtest.h>

TEST(PalindromeTest, ExpandCenter) {
    auto result = expand_center("abba", 1, 2);
    EXPECT_EQ(result.first, 0);
    EXPECT_EQ(result.second, 4);
}

TEST(PalindromeTest, LongestPalindrome) {
    auto result = longest_palindrome("cbbd");
    EXPECT_EQ(result.first, 1);
    EXPECT_EQ(result.second, 2);
}
