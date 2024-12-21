#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/CheckingAccount.h"
#include "../ppois33/CheckingAccount.cpp"
#include <iostream>
#include <sstream>

// Тестирование класса CheckingAccount

// Тест для конструктора и инициализации
TEST(CheckingAccountTest, ConstructorAndInitialization) {
    CheckingAccount account(1, 1000.0, 500.0);

    EXPECT_EQ(account.getId(), 1);  // Проверка ID счета
    EXPECT_EQ(account.getBalance(), 1000.0);  // Проверка начального баланса
    EXPECT_EQ(account.getOverdraftLimit(), 500.0);  // Проверка лимита овердрафта
}

// Тест для метода withdraw (снятие средств с превышением лимита)
TEST(CheckingAccountTest, WithdrawExceedsLimit) {
    CheckingAccount account(1, 1000.0, 500.0);  // Баланс 1000, лимит овердрафта 500

    // Перенаправляем вывод в строковый поток, чтобы проверить сообщение
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // Перехватываем std::cout

    account.withdraw(1600.0);  // Снимаем 1600 (баланс + лимит овердрафта)

    // Проверяем, что вывод совпадает с ожидаемым
    EXPECT_EQ(output.str(), "Недостаточно средств либо превышен лимит трат!\n");

    // Восстанавливаем поток вывода
    std::cout.rdbuf(originalBuffer);

    // Проверяем, что баланс не изменился
    EXPECT_EQ(account.getBalance(), 1000.0);
}

// Тест для метода getOverdraftLimit
TEST(CheckingAccountTest, GetOverdraftLimit) {
    CheckingAccount account(1, 1000.0, 500.0);

    EXPECT_EQ(account.getOverdraftLimit(), 500.0);  // Проверка корректности лимита овердрафта
}

// Тест для метода withdraw с отрицательным лимитом овердрафта
TEST(CheckingAccountTest, WithdrawWithNegativeOverdraftLimit) {
    CheckingAccount account(1, 1000.0, -500.0);  // Лимит овердрафта отрицательный

    // Перенаправляем вывод в строковый поток, чтобы проверить сообщение
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // Перехватываем std::cout

    account.withdraw(1200.0);  // Снимаем 1200, что больше доступного

    // Проверяем, что вывод совпадает с ожидаемым
    EXPECT_EQ(output.str(), "Недостаточно средств либо превышен лимит трат!\n");

    // Восстанавливаем поток вывода
    std::cout.rdbuf(originalBuffer);

    // Проверяем, что баланс не изменился
    EXPECT_EQ(account.getBalance(), 1000.0);
}
