#include <gtest/gtest.h>
#include <fstream>
#include "print.hpp"
#include <gtest/gtest.h>

// Пример функции, которую мы будем тестировать
int add(int a, int b) {
  return a + b;
}

// Тест, который должен пройти
TEST(AddTest, PositiveNumbers) {
  ASSERT_EQ(add(2, 2), 4);
}

// Тест, который мы намеренно сломаем
TEST(AddTest, NegativeNumbers) {
  ASSERT_EQ(add(-2, -2), -5);  // <--- Намеренная ошибка: должно быть -4
}

// Еще один тест, который должен пройти
TEST(AddTest, Zero) {
  ASSERT_EQ(add(0, 0), 0);
}
