// Copyright 2025 UNN-CS
#include <gtest/gtest.h>
#include "alg.h"

// Тесты для checkPrime
TEST(CheckPrimeTest, SmallNumbers) {
  EXPECT_FALSE(checkPrime(0));
  EXPECT_FALSE(checkPrime(1));
  EXPECT_TRUE(checkPrime(2));
  EXPECT_TRUE(checkPrime(3));
  EXPECT_FALSE(checkPrime(4));
}

TEST(CheckPrimeTest, LargePrimes) {
  EXPECT_TRUE(checkPrime(97));
  EXPECT_TRUE(checkPrime(7919));
  EXPECT_FALSE(checkPrime(10000));
}

// Тесты для nPrime
TEST(NPrimeTest, FirstPrimes) {
  EXPECT_EQ(nPrime(1), 2);
  EXPECT_EQ(nPrime(2), 3);
  EXPECT_EQ(nPrime(3), 5);
  EXPECT_EQ(nPrime(4), 7);
  EXPECT_EQ(nPrime(5), 11);
}

TEST(NPrimeTest, LargerValues) {
  EXPECT_EQ(nPrime(10), 29);
  EXPECT_EQ(nPrime(20), 71);
  EXPECT_EQ(nPrime(50), 229);
}

TEST(NPrimeTest, EdgeCases) {
  EXPECT_EQ(nPrime(0), 0);
}

// Тесты для nextPrime
TEST(NextPrimeTest, SmallNumbers) {
  EXPECT_EQ(nextPrime(0), 2);
  EXPECT_EQ(nextPrime(1), 2);
  EXPECT_EQ(nextPrime(2), 3);
  EXPECT_EQ(nextPrime(3), 5);
  EXPECT_EQ(nextPrime(10), 11);
}

TEST(NextPrimeTest, LargerValues) {
  EXPECT_EQ(nextPrime(97), 101);
  EXPECT_EQ(nextPrime(100), 101);
  EXPECT_EQ(nextPrime(1000), 1009);
}

// Тесты для sumPrime
TEST(SumPrimeTest, SmallBounds) {
  EXPECT_EQ(sumPrime(0), 0);
  EXPECT_EQ(sumPrime(1), 0);
  EXPECT_EQ(sumPrime(2), 0);
  EXPECT_EQ(sumPrime(3), 2);
  EXPECT_EQ(sumPrime(10), 17);
}

TEST(SumPrimeTest, LargerBounds) {
  EXPECT_EQ(sumPrime(20), 77);
  EXPECT_EQ(sumPrime(100), 1060);
}
