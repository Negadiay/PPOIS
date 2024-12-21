#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/SavingsAccount.h"
#include "../ppois33/SavingsAccount.cpp"
#include "../ppois33/Account.h"

TEST(SavingsAccountTest, ConstructorAndInitialization) {
    SavingsAccount savingsAccount(101, 1000.0, 5.0);

    EXPECT_EQ(savingsAccount.getId(), 101);
    EXPECT_EQ(savingsAccount.getBalance(), 1000.0);
    EXPECT_EQ(savingsAccount.getInterestRate(), 5.0);
}

TEST(SavingsAccountTest, GetInterestRate) {
    SavingsAccount savingsAccount(101, 1000.0, 5.0);

    EXPECT_EQ(savingsAccount.getInterestRate(), 5.0);
}
