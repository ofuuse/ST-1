// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include <cstdint>
#include "alg.h"

// Тесты для функции checkPrime
TEST(CheckPrimeTest, HandlesSmallNumbers) {
    EXPECT_FALSE(checkPrime(0));  // 0 не простое
    EXPECT_FALSE(checkPrime(1));  // 1 не простое
    EXPECT_TRUE(checkPrime(2));   // 2 простое
    EXPECT_TRUE(checkPrime(3));    // 3 простое
    EXPECT_FALSE(checkPrime(4));  // 4 не простое
    EXPECT_FALSE(checkPrime(9));  // 9 не простое
}

TEST(CheckPrimeTest, HandlesLargeNumbers) {
    EXPECT_TRUE(checkPrime(9973));   // 9973 простое
    EXPECT_FALSE(checkPrime(10000)); // 10000 не простое
    EXPECT_TRUE(checkPrime(7919));  // 7919 простое
    EXPECT_FALSE(checkPrime(7921)); // 7921 не простое (89^2)
}

TEST(CheckPrimeTest, HandlesEdgeCases) {
    EXPECT_FALSE(checkPrime(10007 * 10007)); // Квадрат простого числа
    EXPECT_TRUE(checkPrime(2147483647));     // 2^31 - 1 (простое число Мерсенна)
}

// Тесты для функции nPrime
TEST(NPrimeTest, HandlesFirstPrimes) {
    EXPECT_EQ(nPrime(1), 2);   // 1-е простое число
    EXPECT_EQ(nPrime(2), 3);   // 2-е простое число
    EXPECT_EQ(nPrime(5), 11); // 5-е простое число
    EXPECT_EQ(nPrime(10), 29); // 10-е простое число
}

TEST(NPrimeTest, HandlesLargeN) {
    EXPECT_EQ(nPrime(100), 541); // 100-е простое число
    EXPECT_EQ(nPrime(500), 3571); // 500-е простое число
}

TEST(NPrimeTest, HandlesEdgeCases) {
    EXPECT_EQ(nPrime(0), 0);   // Специальный случай
    EXPECT_EQ(nPrime(1000), 7919); // 1000-е простое число
}

// Тесты для функции nextPrime
TEST(NextPrimeTest, HandlesSmallNumbers) {
    EXPECT_EQ(nextPrime(2), 3);   // Следующее после 2
    EXPECT_EQ(nextPrime(10), 11); // Следующее после 10
    EXPECT_EQ(nextPrime(13), 17); // Следующее после 13
}

TEST(NextPrimeTest, HandlesLargeNumbers) {
    EXPECT_EQ(nextPrime(9972), 9973); // Следующее после 9972
    EXPECT_EQ(nextPrime(10000), 10007); // Следующее после 10000
}

TEST(NextPrimeTest, HandlesEdgeCases) {
    EXPECT_EQ(nextPrime(1), 2);   // Следующее после 1
    EXPECT_EQ(nextPrime(0), 2);   // Следующее после 0
    EXPECT_EQ(nextPrime(2147483647), 2147483659); // Макс 32-битное простое число
}

// Тесты для функции sumPrime
TEST(SumPrimeTest, HandlesSmallBounds) {
    EXPECT_EQ(sumPrime(2), 0);   // Нет простых чисел меньше 2
    EXPECT_EQ(sumPrime(3), 2);   // Только 2
    EXPECT_EQ(sumPrime(10), 17); // 2 + 3 + 5 + 7
    EXPECT_EQ(sumPrime(20), 77); // 2 + 3 + 5 + 7 + 11 + 13 + 17 + 19
}

TEST(SumPrimeTest, HandlesLargeBounds) {
    EXPECT_EQ(sumPrime(100), 1060); // Сумма простых чисел до 100
    EXPECT_EQ(sumPrime(1000), 76127); // Сумма простых чисел до 1000
}

TEST(SumPrimeTest, HandlesEdgeCases) {
    EXPECT_EQ(sumPrime(0), 0);   // Нет чисел меньше 0
    EXPECT_EQ(sumPrime(1), 0);   // Нет простых чисел меньше 1
    EXPECT_EQ(sumPrime(2), 0);   // Нет простых чисел меньше 2
}
