#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/Branch.h"
#include "../ppois33/Branch.cpp"
#include "../ppois33/Account.h"
#include <iostream>

// Тестирование класса Branch

// Тест для конструктора и проверки инициализации данных
TEST(BranchTest, ConstructorAndInitialization) {
    Branch branch(1, "Red Square");

    EXPECT_EQ(branch.getId(), 1);  // Проверка ID филиала
    EXPECT_EQ(branch.getAddress(), "Red Square");  // Проверка адреса филиала
}

// Тест для метода addAccount
TEST(BranchTest, AddAccount) {
    Branch branch(1, "Red Square");
    Account account(1, 1000.0);  // Создаем аккаунт с балансом 1000

    branch.addAccount(&account);

    const auto& accounts = branch.getAccounts();
    EXPECT_EQ(accounts.size(), 1);  // Проверяем, что аккаунт добавлен
    EXPECT_EQ(accounts[0]->getId(), 1);  // Проверяем, что ID аккаунта совпадает
    EXPECT_EQ(accounts[0]->getBalance(), 1000.0);  // Проверяем, что баланс аккаунта верный
}

// Тест для метода getAccounts, когда в филиале несколько аккаунтов
TEST(BranchTest, MultipleAccounts) {
    Branch branch(1, "Red Square");
    Account account1(1, 1000.0);
    Account account2(2, 2000.0);

    branch.addAccount(&account1);
    branch.addAccount(&account2);

    const auto& accounts = branch.getAccounts();
    EXPECT_EQ(accounts.size(), 2);  // Проверяем, что оба аккаунта добавлены
    EXPECT_EQ(accounts[0]->getId(), 1);  // Проверяем, что первый аккаунт имеет правильный ID
    EXPECT_EQ(accounts[1]->getId(), 2);  // Проверяем, что второй аккаунт имеет правильный ID
    EXPECT_EQ(accounts[1]->getBalance(), 2000.0);  // Проверяем баланс второго аккаунта
}

// Тест для метода getAccounts, когда в филиале нет аккаунтов
TEST(BranchTest, NoAccounts) {
    Branch branch(1, "Red Square");

    const auto& accounts = branch.getAccounts();
    EXPECT_EQ(accounts.size(), 0);  // Проверяем, что в списке нет аккаунтов
}

// Тест для метода getId
TEST(BranchTest, GetId) {
    Branch branch(1, "Red Square");

    EXPECT_EQ(branch.getId(), 1);  // Проверяем, что ID филиала верный
}

// Тест для добавления аккаунта с отрицательным балансом
TEST(BranchTest, AddAccountWithNegativeBalance) {
    Branch branch(1, "Red Square");
    Account account(1, -500.0);  // Создаем аккаунт с отрицательным балансом

    branch.addAccount(&account);

    const auto& accounts = branch.getAccounts();
    EXPECT_EQ(accounts.size(), 1);  // Проверяем, что аккаунт добавлен
    EXPECT_EQ(accounts[0]->getId(), 1);  // Проверяем, что ID аккаунта совпадает
    EXPECT_EQ(accounts[0]->getBalance(), -500.0);  // Проверяем, что баланс аккаунта верный (отрицательный)
}
