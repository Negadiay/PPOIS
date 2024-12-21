#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/CreditCard.h"
#include "../ppois33/CreditCard.cpp"
#include "../ppois33/Account.h"
#include <iostream>
#include <sstream>

// Тестирование класса CreditCard

// Тест для конструктора и инициализации
TEST(CreditCardTest, ConstructorAndInitialization) {
    Account account(1, 1000.0);  // Создаем аккаунт с балансом 1000
    CreditCard card(1234567890, 5000.0, &account);  // Карта с лимитом 5000

    EXPECT_EQ(card.getCardNumber(), 1234567890);  // Проверка номера карты
    EXPECT_EQ(card.getCreditLimit(), 5000.0);  // Проверка кредитного лимита
    EXPECT_EQ(card.getBalance(), 0.0);  // Баланс карты должен быть 0
}

// Тест для метода charge (списание средств в пределах лимита)
TEST(CreditCardTest, ChargeWithinLimit) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);

    // Перенаправляем вывод в строковый поток, чтобы проверить сообщение
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // Перехватываем std::cout

    card.charge(2000.0);  // Снимаем 2000, что меньше лимита 5000

    // Проверяем, что вывод совпадает с ожидаемым
    EXPECT_EQ(output.str(), "Переведено 2000 на карту 1234567890\n");

    // Восстанавливаем поток вывода
    std::cout.rdbuf(originalBuffer);

    // Проверяем баланс карты после операции
    EXPECT_EQ(card.getBalance(), 2000.0);
}

// Тест для метода charge (списание средств, превышающих лимит)
TEST(CreditCardTest, ChargeExceedsLimit) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);

    // Перенаправляем вывод в строковый поток, чтобы проверить сообщение
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // Перехватываем std::cout

    card.charge(6000.0);  // Снимаем 6000, что превышает лимит 5000

    // Проверяем, что вывод совпадает с ожидаемым
    EXPECT_EQ(output.str(), "Сумма превышает кредитный лимит!\n");

    // Восстанавливаем поток вывода
    std::cout.rdbuf(originalBuffer);

    // Проверяем, что баланс карты не изменился
    EXPECT_EQ(card.getBalance(), 0.0);
}

// Тест для метода makePayment (оплата средств с карты)
TEST(CreditCardTest, MakePayment) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);

    card.charge(2000.0);  // Снимаем 2000
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // Перехватываем std::cout

    card.makePayment(1000.0);  // Платим 1000

    // Проверяем, что вывод совпадает с ожидаемым
    EXPECT_EQ(output.str(), "Оплата 1000 была проведена с карты 1234567890\n");

    // Восстанавливаем поток вывода
    std::cout.rdbuf(originalBuffer);

    // Проверяем, что баланс карты после оплаты уменьшился
    EXPECT_EQ(card.getBalance(), 1000.0);  // 2000 - 1000 = 1000
}

// Тест для метода getBalance (получение текущего баланса карты)
TEST(CreditCardTest, GetBalance) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);

    card.charge(1000.0);  // Снимаем 1000

    EXPECT_EQ(card.getBalance(), 1000.0);  // Баланс карты после снятия должен быть 1000
}

// Тест для метода getCreditLimit (получение лимита карты)
TEST(CreditCardTest, GetCreditLimit) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);

    EXPECT_EQ(card.getCreditLimit(), 5000.0);  // Лимит карты должен быть 5000
}

// Тест для метода getCardNumber (получение номера карты)
TEST(CreditCardTest, GetCardNumber) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);

    EXPECT_EQ(card.getCardNumber(), 1234567890);  // Номер карты должен быть 1234567890
}
