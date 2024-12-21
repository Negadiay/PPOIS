#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/Account.h"
#include "../ppois33/Account.cpp"
#include "../ppois33/Transaction.h"

TEST(AccountTest, ConstructorAndInitialization) {
    Account account(101, 1000.0);

    EXPECT_EQ(account.getId(), 101);
    EXPECT_EQ(account.getBalance(), 1000.0);
}

TEST(AccountTest, Deposit) {
    Account account(101, 1000.0);
    double initialBalance = account.getBalance();

    account.deposit(500.0);
    EXPECT_EQ(account.getBalance(), initialBalance + 500.0);
}

TEST(AccountTest, Withdraw) {
    Account account(101, 1000.0);
    double initialBalance = account.getBalance();

    account.withdraw(300.0);
    EXPECT_EQ(account.getBalance(), initialBalance - 300.0);

    testing::internal::CaptureStdout();
    account.withdraw(1000.0); 
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "Ошибка: Недостаточно средств для снятия!\n");
}


