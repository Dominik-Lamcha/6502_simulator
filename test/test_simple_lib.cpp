#include <gtest/gtest.h>
#include "simple_lib.hpp"

TEST(SimpleMathTest, TestAddition) {
    EXPECT_DOUBLE_EQ(simple_lib::add(1.0, 2.0), 3.0);
    EXPECT_DOUBLE_EQ(simple_lib::add(-1.0, 2.0), 1.0);
    EXPECT_DOUBLE_EQ(simple_lib::add(0.0, 0.0), 0.0);
}

// Add more TEST() macros as needed for other functions or edge cases.
