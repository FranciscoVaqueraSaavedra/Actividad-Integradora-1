//
// Created by Franc on 20/05/2025.
//

#include "utils.h"
#include <gtest/gtest.h>

TEST(UtilsTest, ContainsPatternFound) {
    auto result = contains_pattern("Hola mundo", "mundo");
    EXPECT_TRUE(result.first);
    EXPECT_EQ(result.second, 6);
}

TEST(UtilsTest, ContainsPatternNotFound) {
    auto result = contains_pattern("Hola mundo", "adios");
    EXPECT_FALSE(result.first);
    EXPECT_EQ(result.second, 0);
}

