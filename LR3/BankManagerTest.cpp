#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/BankManager.h"
#include "../ppois33/BankManager.cpp"
#include <iostream>
#include <sstream>

// Тестирование класса BankManager

// Тест для конструктора и проверки имени и зарплаты
TEST(BankManagerTest, ConstructorAndGetSalary) {
    BankManager manager(1, "Ivan Ivanov", 50000.0);

    // Проверяем, что данные инициализированы корректно
    EXPECT_EQ(manager.getSalary(), 50000.0);  // Проверка зарплаты
    EXPECT_EQ(manager.getName(), "Ivan Ivanov");  // Проверка имени
}

// Тест для метода approveLoan
TEST(BankManagerTest, ApproveLoan) {
    BankManager manager(1, "Ivan Ivanov", 50000.0);

    // Перенаправляем вывод в строковый поток, чтобы проверить, что выводится
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // Перехватываем std::cout

    manager.approveLoan();

    // Сравниваем вывод с ожидаемой строкой
    EXPECT_EQ(output.str(), "Кредит одобрен менеджером банка: Ivan Ivanov\n");

    // Восстанавливаем поток вывода
    std::cout.rdbuf(originalBuffer);
}

// Тест для метода getSalary с разными значениями
TEST(BankManagerTest, GetSalary) {
    BankManager manager(1, "Ivan Ivanov", 50000.0);
    EXPECT_EQ(manager.getSalary(), 50000.0);

    manager = BankManager(2, "Petr Petrov", 70000.0);
    EXPECT_EQ(manager.getSalary(), 70000.0);
}

// Тест для пустого имени менеджера
TEST(BankManagerTest, EmptyName) {
    BankManager manager(1, "", 50000.0);
    EXPECT_EQ(manager.getSalary(), 50000.0);
    EXPECT_EQ(manager.getName(), "");  // Проверяем, что имя пустое
}

// Тест для изменения зарплаты после создания объекта
TEST(BankManagerTest, SalaryUpdate) {
    BankManager manager(1, "Ivan Ivanov", 50000.0);
    EXPECT_EQ(manager.getSalary(), 50000.0);

    // Допустим, что мы обновили зарплату
    manager = BankManager(1, "Ivan Ivanov", 55000.0);  // Пересоздаем объект с новой зарплатой
    EXPECT_EQ(manager.getSalary(), 55000.0);
}
