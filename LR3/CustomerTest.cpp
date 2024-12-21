#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/Customer.h"
#include "../ppois33/Customer.cpp"
#include "../ppois33/Account.h"

TEST(CustomerTest, ConstructorAndInitialization) {
    Customer customer(101, "John Doe");

    EXPECT_EQ(customer.getId(), 101);
    EXPECT_EQ(customer.getName(), "John Doe");
}

TEST(CustomerTest, AddAccount) {
    Customer customer(101, "John Doe");
    Account* account1 = new Account(201, 1000.0);
    Account* account2 = new Account(202, 1500.0);

    customer.addAccount(account1);
    customer.addAccount(account2);

    const auto& accounts = customer.getAccounts();
    EXPECT_EQ(accounts.size(), 2);
    EXPECT_EQ(accounts[0]->getId(), 201);
    EXPECT_EQ(accounts[1]->getId(), 202);

    delete account1;
    delete account2;
}

TEST(CustomerTest, GetAccounts) {
    Customer customer(101, "John Doe");
    Account* account1 = new Account(201, 1000.0);
    Account* account2 = new Account(202, 1500.0);

    customer.addAccount(account1);
    customer.addAccount(account2);

    const auto& accounts = customer.getAccounts();
    EXPECT_EQ(accounts.size(), 2);
    EXPECT_EQ(accounts[0]->getBalance(), 1000.0);
    EXPECT_EQ(accounts[1]->getBalance(), 1500.0);

    delete account1;
    delete account2;
}
