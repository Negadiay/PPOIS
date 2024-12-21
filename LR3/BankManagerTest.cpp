#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/BankManager.h"
#include "../ppois33/BankManager.cpp"
#include <iostream>
#include <sstream>

TEST(BankManagerTest, ConstructorAndGetSalary) {
    BankManager manager(1, "Ivan Ivanov", 50000.0);

    EXPECT_EQ(manager.getSalary(), 50000.0);  
    EXPECT_EQ(manager.getName(), "Ivan Ivanov");  
}

TEST(BankManagerTest, ApproveLoan) {
    BankManager manager(1, "Ivan Ivanov", 50000.0);

    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf()); 

    manager.approveLoan();

    EXPECT_EQ(output.str(), "Кредит одобрен менеджером банка: Ivan Ivanov\n");

    std::cout.rdbuf(originalBuffer);
}

TEST(BankManagerTest, GetSalary) {
    BankManager manager(1, "Ivan Ivanov", 50000.0);
    EXPECT_EQ(manager.getSalary(), 50000.0);

    manager = BankManager(2, "Petr Petrov", 70000.0);
    EXPECT_EQ(manager.getSalary(), 70000.0);
}

TEST(BankManagerTest, EmptyName) {
    BankManager manager(1, "", 50000.0);
    EXPECT_EQ(manager.getSalary(), 50000.0);
    EXPECT_EQ(manager.getName(), "");  
}

TEST(BankManagerTest, SalaryUpdate) {
    BankManager manager(1, "Ivan Ivanov", 50000.0);
    EXPECT_EQ(manager.getSalary(), 50000.0);

    manager = BankManager(1, "Ivan Ivanov", 55000.0);  
    EXPECT_EQ(manager.getSalary(), 55000.0);
}
