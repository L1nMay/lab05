#include "gtest/gtest.h"
#include "print.hpp"

TEST(AddTest, PositiveNumbers) {
    ASSERT_EQ(add(2, 2), 4);
}

TEST(AddTest, NegativeNumbers) {
    ASSERT_EQ(add(-2, -2), -4);  // Исправлено: ожидаем -4, а не -5
}

TEST(AddTest, Zero) {
    ASSERT_EQ(add(0, 0), 0);
}
