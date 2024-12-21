#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/CreditCard.h"
#include "../ppois33/CreditCard.cpp"
#include "../ppois33/Account.h"
#include <iostream>
#include <sstream>

TEST(CreditCardTest, ConstructorAndInitialization) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);
    EXPECT_EQ(card.getCardNumber(), 1234567890);
    EXPECT_EQ(card.getCreditLimit(), 5000.0);
    EXPECT_EQ(card.getBalance(), 0.0);
}

TEST(CreditCardTest, ChargeWithinLimit) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());
    card.charge(2000.0);
    EXPECT_EQ(output.str(), "Переведено 2000 на карту 1234567890\n");
    std::cout.rdbuf(originalBuffer);
    EXPECT_EQ(card.getBalance(), 2000.0);
}

TEST(CreditCardTest, ChargeExceedsLimit) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());
    card.charge(6000.0);
    EXPECT_EQ(output.str(), "Сумма превышает кредитный лимит!\n");
    std::cout.rdbuf(originalBuffer);
    EXPECT_EQ(card.getBalance(), 0.0);
}

TEST(CreditCardTest, MakePayment) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);
    card.charge(2000.0);
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());
    card.makePayment(1000.0);
    EXPECT_EQ(output.str(), "Оплата 1000 была проведена с карты 1234567890\n");
    std::cout.rdbuf(originalBuffer);
    EXPECT_EQ(card.getBalance(), 1000.0);
}

TEST(CreditCardTest, GetBalance) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);
    card.charge(1000.0);
    EXPECT_EQ(card.getBalance(), 1000.0);
}

TEST(CreditCardTest, GetCreditLimit) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);
    EXPECT_EQ(card.getCreditLimit(), 5000.0);
}

TEST(CreditCardTest, GetCardNumber) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);
    EXPECT_EQ(card.getCardNumber(), 1234567890);
}
