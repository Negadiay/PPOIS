#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/Branch.h"
#include "../ppois33/Branch.cpp"
#include "../ppois33/Account.h"
#include <iostream>

TEST(BranchTest, ConstructorAndInitialization) {
    Branch branch(1, "Red Square");

    EXPECT_EQ(branch.getId(), 1);
    EXPECT_EQ(branch.getAddress(), "Red Square");
}

TEST(BranchTest, AddAccount) {
    Branch branch(1, "Red Square");
    Account account(1, 1000.0);

    branch.addAccount(&account);

    const auto& accounts = branch.getAccounts();
    EXPECT_EQ(accounts.size(), 1);
    EXPECT_EQ(accounts[0]->getId(), 1);
    EXPECT_EQ(accounts[0]->getBalance(), 1000.0);
}

TEST(BranchTest, MultipleAccounts) {
    Branch branch(1, "Red Square");
    Account account1(1, 1000.0);
    Account account2(2, 2000.0);

    branch.addAccount(&account1);
    branch.addAccount(&account2);

    const auto& accounts = branch.getAccounts();
    EXPECT_EQ(accounts.size(), 2);
    EXPECT_EQ(accounts[0]->getId(), 1);
    EXPECT_EQ(accounts[1]->getId(), 2);
    EXPECT_EQ(accounts[1]->getBalance(), 2000.0);
}

TEST(BranchTest, NoAccounts) {
    Branch branch(1, "Red Square");

    const auto& accounts = branch.getAccounts();
    EXPECT_EQ(accounts.size(), 0);
}

TEST(BranchTest, GetId) {
    Branch branch(1, "Red Square");

    EXPECT_EQ(branch.getId(), 1);
}

TEST(BranchTest, AddAccountWithNegativeBalance) {
    Branch branch(1, "Red Square");
    Account account(1, -500.0);

    branch.addAccount(&account);

    const auto& accounts = branch.getAccounts();
    EXPECT_EQ(accounts.size(), 1);
    EXPECT_EQ(accounts[0]->getId(), 1);
    EXPECT_EQ(accounts[0]->getBalance(), -500.0);
}