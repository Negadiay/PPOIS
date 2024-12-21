#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/Loan.h"
#include "../ppois33/Loan.cpp"
#include <sstream>

// Тестирование класса Loan

// Тест для конструктора и инициализации
TEST(LoanTest, ConstructorAndInitialization) {
    Loan loan(10000.0, 5.0, "2025-12-31");  // Создаем кредит на 10000 с процентной ставкой 5.0 и датой погашения 2025-12-31

    EXPECT_EQ(loan.getAmount(), 10000.0);  // Проверка начальной суммы кредита
    EXPECT_EQ(loan.getInterestRate(), 5.0);  // Проверка процентной ставки
    EXPECT_EQ(loan.getDueDate(), "2025-12-31");  // Проверка даты погашения
}

// Тест для метода approveLoan (одобрение кредита)
TEST(LoanTest, ApproveLoan) {
    Loan loan(10000.0, 5.0, "2025-12-31");

    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // Перехватываем std::cout

    loan.approveLoan();  // Одобряем кредит

    // Проверяем, что вывод совпадает с ожидаемым
    EXPECT_EQ(output.str(), "Кредит одобрен.\n");

    // Восстанавливаем поток вывода
    std::cout.rdbuf(originalBuffer);
}

// Тест для метода payInstallment (оплата части кредита после его одобрения)
TEST(LoanTest, PayInstallmentAfterApproval) {
    Loan loan(10000.0, 5.0, "2025-12-31");
    loan.approveLoan();  // Одобряем кредит

    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // Перехватываем std::cout

    loan.payInstallment(2000.0);  // Платим 2000

    // Проверяем вывод
    EXPECT_EQ(output.str(), "Оплаченная сумма кредита: 2000, оставшаяся задолженность: 8000\n");

    // Восстанавливаем поток вывода
    std::cout.rdbuf(originalBuffer);

    // Проверяем, что остаточная сумма кредита уменьшилась
    EXPECT_EQ(loan.getAmount(), 8000.0);  // Остаток после оплаты должен быть 8000
}

// Тест для метода payInstallment (попытка оплаты до одобрения кредита)
TEST(LoanTest, PayInstallmentBeforeApproval) {
    Loan loan(10000.0, 5.0, "2025-12-31");

    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // Перехватываем std::cout

    loan.payInstallment(2000.0);  // Платим до одобрения кредита

    // Проверяем вывод ошибки
    EXPECT_EQ(output.str(), "Кредит еще не одобрен.\n");

    // Восстанавливаем поток вывода
    std::cout.rdbuf(originalBuffer);

    // Проверяем, что остаточная сумма кредита не изменилась
    EXPECT_EQ(loan.getAmount(), 10000.0);  // Остаток должен остаться 10000
}

// Тест для метода getAmount (получение остаточной суммы кредита)
TEST(LoanTest, GetAmount) {
    Loan loan(10000.0, 5.0, "2025-12-31");
    loan.approveLoan();  // Одобряем кредит

    loan.payInstallment(2000.0);  // Платим 2000

    EXPECT_EQ(loan.getAmount(), 8000.0);  // Остаток после оплаты должен быть 8000
}

// Тест для метода getInterestRate (получение процентной ставки)
TEST(LoanTest, GetInterestRate) {
    Loan loan(10000.0, 5.0, "2025-12-31");

    EXPECT_EQ(loan.getInterestRate(), 5.0);  // Процентная ставка должна быть 5.0
}

// Тест для метода getDueDate (получение даты погашения)
TEST(LoanTest, GetDueDate) {
    Loan loan(10000.0, 5.0, "2025-12-31");

    EXPECT_EQ(loan.getDueDate(), "2025-12-31");  // Дата погашения должна быть 2025-12-31
}
