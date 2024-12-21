#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/TransactionHistory.h"
#include "../ppois33/TransactionHistory.cpp"
#include "../ppois33/Transaction.h"
#include "../ppois33/Account.h"
#include <sstream>

// Тест для метода addTransaction
TEST(TransactionHistoryTest, AddTransaction) {
    Account account(1, 1000.0);
    Transaction transaction(&account, "Пополнить", 500.0, "2024-12-01");

    TransactionHistory history;
    history.addTransaction(&transaction);

    const auto& transactions = history.getTransactions();
    EXPECT_EQ(transactions.size(), 1);  // Должна быть добавлена одна транзакция
    EXPECT_EQ(transactions[0]->getAmount(), 500.0);  // Сумма транзакции должна быть 500.0
    EXPECT_EQ(transactions[0]->getTimestamp(), "2024-12-01");  // Временная метка должна быть "2024-12-01"
}

// Тест для метода printHistory
TEST(TransactionHistoryTest, PrintHistory) {
    Account account(1, 1000.0);
    Transaction transaction1(&account, "Пополнить", 500.0, "2024-12-01");
    Transaction transaction2(&account, "Снять", 200.0, "2024-12-02");

    TransactionHistory history;
    history.addTransaction(&transaction1);
    history.addTransaction(&transaction2);

    testing::internal::CaptureStdout();
    history.printHistory();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("Перевод в размере 500"), std::string::npos);  // Проверка на наличие первого перевода
    EXPECT_NE(output.find("Перевод в размере 200"), std::string::npos);  // Проверка на наличие второго перевода
    EXPECT_NE(output.find("на период 2024-12-01"), std::string::npos);  // Проверка на правильность даты первого перевода
    EXPECT_NE(output.find("на период 2024-12-02"), std::string::npos);  // Проверка на правильность даты второго перевода
}

// Тест для метода getTransactions (возвращает все транзакции)
TEST(TransactionHistoryTest, GetTransactions) {
    Account account(1, 1000.0);
    Transaction transaction1(&account, "Пополнить", 500.0, "2024-12-01");
    Transaction transaction2(&account, "Снять", 200.0, "2024-12-02");

    TransactionHistory history;
    history.addTransaction(&transaction1);
    history.addTransaction(&transaction2);

    const auto& transactions = history.getTransactions();
    EXPECT_EQ(transactions.size(), 2);  // Должны быть две транзакции
    EXPECT_EQ(transactions[0]->getAmount(), 500.0);  // Проверка суммы первой транзакции
    EXPECT_EQ(transactions[1]->getAmount(), 200.0);  // Проверка суммы второй транзакции
}

// Тест на пустую историю транзакций
TEST(TransactionHistoryTest, EmptyHistory) {
    TransactionHistory history;
    const auto& transactions = history.getTransactions();

    EXPECT_EQ(transactions.size(), 0);  // История транзакций должна быть пуста
}

// Тест для метода printHistory при отсутствии транзакций
TEST(TransactionHistoryTest, PrintEmptyHistory) {
    TransactionHistory history;

    testing::internal::CaptureStdout();
    history.printHistory();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "");  // При пустой истории ничего не выводится
}
