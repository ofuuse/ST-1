// Copyright 2025 UNN-CS
#include <cstdint>
#include <cmath>
#include "alg.h"

// Функция для проверки числа на простоту
bool checkPrime(uint64_t value) {
    if (value < 2) return false; // Числа меньше 2 не являются простыми
    if (value == 2) return true; // 2 — единственное четное простое число
    if (value % 2 == 0) return false; // Остальные четные числа не простые

    // Проверяем делители до квадратного корня из value
    for (uint64_t i = 3; i <= sqrt(value); i += 2) {
        if (value % i == 0) {
            return false;
        }
    }
    return true;
}

// Функция для нахождения n-го простого числа
uint64_t nPrime(uint64_t n) {
    if (n == 0) return 0; // Нулевое простое число не существует

    uint64_t count = 0; // Счетчик найденных простых чисел
    uint64_t num = 2;   // Начинаем с первого простого числа

    while (count < n) {
        if (checkPrime(num)) {
            count++;
        }
        num++;
    }
    return num - 1; // Возвращаем последнее найденное простое число
}

// Функция для нахождения ближайшего следующего простого числа
uint64_t nextPrime(uint64_t value) {
    uint64_t num = value + 1; // Начинаем поиск со следующего числа

    while (true) {
        if (checkPrime(num)) {
            return num;
        }
        num++;
    }
}

// Функция для нахождения суммы всех простых чисел до hbound
uint64_t sumPrime(uint64_t hbound) {
    uint64_t sum = 0;

    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            sum += i;
        }
    }
    return sum;
}
