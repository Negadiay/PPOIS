#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/Transaction.h"
#include "../ppois33/Transaction.cpp"
#include "../ppois33/Account.h"
#include <iostream>

TEST(TransactionTest, ExecuteWithdrawalInsufficientFunds) {
    Account account(1, 100.0);
    Transaction withdrawal(&account, "Withdrawal", 150.0, "2024-12-20T12:00:00");
    withdrawal.execute();
    EXPECT_EQ(account.getBalance(), 100.0);
}

TEST(TransactionTest, InvalidTransactionType) {
    Account account(1, 100.0);
    Transaction invalidTransaction(&account, "InvalidType", 50.0, "2024-12-20T12:00:00");
    invalidTransaction.execute();
    EXPECT_EQ(account.getBalance(), 100.0);
}

TEST(TransactionTest, GetType) {
    Account account(1, 100.0);
    Transaction transaction(&account, "Withdrawal", 50.0, "2024-12-20T12:00:00");
    EXPECT_EQ(transaction.getType(), "Withdrawal");
}
