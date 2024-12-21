#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/Bank.h"
#include "../ppois33/Bank.cpp"
#include "../ppois33/Customer.h"
#include "../ppois33/Branch.h"
#include <iostream>
#include <sstream>


TEST(BankTest, ConstructorAndInitialization) {
    Bank bank("Sberbank", "Moscow");

    EXPECT_EQ(bank.getName(), "Sberbank");  
    EXPECT_EQ(bank.getAddress(), "Moscow");  
}

TEST(BankTest, AddCustomer) {
    Bank bank("Sberbank", "Moscow");
    Customer customer(1, "Ivan Ivanov");

    bank.addCustomer(&customer);

    const auto& customers = bank.getCustomers();
    EXPECT_EQ(customers.size(), 1);
    EXPECT_EQ(customers[0]->getId(), 1);
    EXPECT_EQ(customers[0]->getName(), "Ivan Ivanov");
}

TEST(BankTest, AddBranch) {
    Bank bank("Sberbank", "Moscow");
    Branch branch(1, "Red Square");

    bank.addBranch(&branch);

    const auto& branches = bank.getBranches();
    EXPECT_EQ(branches.size(), 1);
    EXPECT_EQ(branches[0]->getId(), 1);
    EXPECT_EQ(branches[0]->getAddress(), "Red Square");
}

TEST(BankTest, TransferFunds) {
    Bank bank("Sberbank", "Moscow");

    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  

    bank.transferFunds(12345, 67890, 1000.0);

    EXPECT_EQ(output.str(), "Переведено рублей 1000 со счёта 12345 на счёт 67890\n");

    std::cout.rdbuf(originalBuffer);
}

TEST(BankTest, PrintCustomers) {
    Bank bank("Sberbank", "Moscow");
    Customer customer1(1, "Ivan Ivanov");
    Customer customer2(2, "Petr Petrov");

    bank.addCustomer(&customer1);
    bank.addCustomer(&customer2);

    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  

    bank.printCustomers();

    EXPECT_EQ(output.str(), "Клиенты: \nКлиент ID: 1, Имя: Ivan Ivanov\nКлиент ID: 2, Имя: Petr Petrov\n");

    std::cout.rdbuf(originalBuffer);
}

TEST(BankTest, PrintBranches) {
    Bank bank("Sberbank", "Moscow");
    Branch branch1(1, "Red Square");
    Branch branch2(2, "Tverskaya");

    bank.addBranch(&branch1);
    bank.addBranch(&branch2);

    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  

    bank.printBranches();

    EXPECT_EQ(output.str(), "Филиалы: \nФилиал ID: 1, Адрес: Red Square\nФилиал ID: 2, Адрес: Tverskaya\n");

    std::cout.rdbuf(originalBuffer);
}
