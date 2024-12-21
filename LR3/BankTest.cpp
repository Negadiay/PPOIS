#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/Bank.h"
#include "../ppois33/Bank.cpp"
#include "../ppois33/Customer.h"
#include "../ppois33/Branch.h"
#include <iostream>
#include <sstream>

// Тестирование класса Bank

// Тест для конструктора и проверки инициализации имени и адреса
TEST(BankTest, ConstructorAndInitialization) {
    Bank bank("Sberbank", "Moscow");

    EXPECT_EQ(bank.getName(), "Sberbank");  // Проверяем имя банка
    EXPECT_EQ(bank.getAddress(), "Moscow");  // Проверяем адрес банка
}

// Тест для метода addCustomer
TEST(BankTest, AddCustomer) {
    Bank bank("Sberbank", "Moscow");
    Customer customer(1, "Ivan Ivanov");

    bank.addCustomer(&customer);

    const auto& customers = bank.getCustomers();
    EXPECT_EQ(customers.size(), 1);
    EXPECT_EQ(customers[0]->getId(), 1);
    EXPECT_EQ(customers[0]->getName(), "Ivan Ivanov");
}

// Тест для метода addBranch
TEST(BankTest, AddBranch) {
    Bank bank("Sberbank", "Moscow");
    Branch branch(1, "Red Square");

    bank.addBranch(&branch);

    const auto& branches = bank.getBranches();
    EXPECT_EQ(branches.size(), 1);
    EXPECT_EQ(branches[0]->getId(), 1);
    EXPECT_EQ(branches[0]->getAddress(), "Red Square");
}

// Тест для метода transferFunds
TEST(BankTest, TransferFunds) {
    Bank bank("Sberbank", "Moscow");

    // Перенаправляем вывод в строковый поток, чтобы проверить сообщение
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // Перехватываем std::cout

    bank.transferFunds(12345, 67890, 1000.0);

    // Проверяем, что вывод совпадает с ожидаемым
    EXPECT_EQ(output.str(), "Переведено рублей 1000 со счёта 12345 на счёт 67890\n");

    // Восстанавливаем поток вывода
    std::cout.rdbuf(originalBuffer);
}

// Тест для метода printCustomers
TEST(BankTest, PrintCustomers) {
    Bank bank("Sberbank", "Moscow");
    Customer customer1(1, "Ivan Ivanov");
    Customer customer2(2, "Petr Petrov");

    bank.addCustomer(&customer1);
    bank.addCustomer(&customer2);

    // Перенаправляем вывод в строковый поток
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // Перехватываем std::cout

    bank.printCustomers();

    // Проверяем, что вывод совпадает с ожидаемым
    EXPECT_EQ(output.str(), "Клиенты: \nКлиент ID: 1, Имя: Ivan Ivanov\nКлиент ID: 2, Имя: Petr Petrov\n");

    // Восстанавливаем поток вывода
    std::cout.rdbuf(originalBuffer);
}

// Тест для метода printBranches
TEST(BankTest, PrintBranches) {
    Bank bank("Sberbank", "Moscow");
    Branch branch1(1, "Red Square");
    Branch branch2(2, "Tverskaya");

    bank.addBranch(&branch1);
    bank.addBranch(&branch2);

    // Перенаправляем вывод в строковый поток
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // Перехватываем std::cout

    bank.printBranches();

    // Проверяем, что вывод совпадает с ожидаемым
    EXPECT_EQ(output.str(), "Филиалы: \nФилиал ID: 1, Адрес: Red Square\nФилиал ID: 2, Адрес: Tverskaya\n");

    // Восстанавливаем поток вывода
    std::cout.rdbuf(originalBuffer);
}
