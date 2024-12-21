#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/CheckingAccount.h"
#include "../ppois33/CheckingAccount.cpp"
#include <iostream>
#include <sstream>

TEST(CheckingAccountTest, ConstructorAndInitialization) {
    CheckingAccount account(1, 1000.0, 500.0);
    EXPECT_EQ(account.getId(), 1);
    EXPECT_EQ(account.getBalance(), 1000.0);
    EXPECT_EQ(account.getOverdraftLimit(), 500.0);
}

TEST(CheckingAccountTest, WithdrawExceedsLimit) {
    CheckingAccount account(1, 1000.0, 500.0);
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());
    account.withdraw(1600.0);
    EXPECT_EQ(output.str(), "Ќедостаточно средств либо превышен лимит трат!\n");
    std::cout.rdbuf(originalBuffer);
    EXPECT_EQ(account.getBalance(), 1000.0);
}

TEST(CheckingAccountTest, GetOverdraftLimit) {
    CheckingAccount account(1, 1000.0, 500.0);
    EXPECT_EQ(account.getOverdraftLimit(), 500.0);
}

TEST(CheckingAccountTest, WithdrawWithNegativeOverdraftLimit) {
    CheckingAccount account(1, 1000.0, -500.0);
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());
    account.withdraw(1200.0);
    EXPECT_EQ(output.str(), "Ќедостаточно средств либо превышен лимит трат!\n");
    std::cout.rdbuf(originalBuffer);
    EXPECT_EQ(account.getBalance(), 1000.0);
}
