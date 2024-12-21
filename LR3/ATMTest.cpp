#include "gtest/gtest.h"
#include "pch.h"    
#include "../ppois33/ATM.h"
#include "../ppois33/ATM.cpp"
#include "../ppois33/Account.h"
#include <iostream>

// Тестирование класса ATM

// Тест для конструктора ATM
TEST(ATMTest, Constructor) {
    ATM atm(1, "Downtown");
    EXPECT_EQ(atm.getAtmId(), 1);
    EXPECT_EQ(atm.getLocation(), "Downtown");
}

// Тест для депозита через банкомат
TEST(ATMTest, Deposit) {
    Account account(1, 100.0);  // Начальный баланс 100
    ATM atm(1, "Downtown");

    atm.deposit(&account, 50.0);  // Депозит 50
    EXPECT_EQ(account.getBalance(), 150.0);  // Баланс должен быть 150
}

// Тест для снятия средств через банкомат с достаточным балансом
TEST(ATMTest, Withdraw) {
    Account account(1, 200.0);  // Начальный баланс 200
    ATM atm(1, "Downtown");

    atm.withdraw(&account, 50.0);  // Снятие 50
    EXPECT_EQ(account.getBalance(), 150.0);  // Баланс должен быть 150
}

// Тест для снятия средств через банкомат с недостаточным балансом
TEST(ATMTest, WithdrawInsufficientFunds) {
    Account account(1, 100.0);  // Начальный баланс 100
    ATM atm(1, "Downtown");

    atm.withdraw(&account, 150.0);  // Снятие 150 не должно быть выполнено
    EXPECT_EQ(account.getBalance(), 100.0);  // Баланс остается 100
}

// Тест для нескольких операций с банкоматом
TEST(ATMTest, MultipleTransactions) {
    Account account(1, 100.0);  // Начальный баланс 100
    ATM atm(1, "Downtown");

    atm.deposit(&account, 50.0);  // Депозит 50
    EXPECT_EQ(account.getBalance(), 150.0);

    atm.withdraw(&account, 30.0);  // Снятие 30
    EXPECT_EQ(account.getBalance(), 120.0);

    atm.deposit(&account, 100.0);  // Депозит 100
    EXPECT_EQ(account.getBalance(), 220.0);

    atm.withdraw(&account, 50.0);  // Снятие 50
    EXPECT_EQ(account.getBalance(), 170.0);
}
