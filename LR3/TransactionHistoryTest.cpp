#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/TransactionHistory.h"
#include "../ppois33/TransactionHistory.cpp"
#include "../ppois33/Transaction.h"
#include "../ppois33/Account.h"
#include <sstream>

// ���� ��� ������ addTransaction
TEST(TransactionHistoryTest, AddTransaction) {
    Account account(1, 1000.0);
    Transaction transaction(&account, "���������", 500.0, "2024-12-01");

    TransactionHistory history;
    history.addTransaction(&transaction);

    const auto& transactions = history.getTransactions();
    EXPECT_EQ(transactions.size(), 1);  // ������ ���� ��������� ���� ����������
    EXPECT_EQ(transactions[0]->getAmount(), 500.0);  // ����� ���������� ������ ���� 500.0
    EXPECT_EQ(transactions[0]->getTimestamp(), "2024-12-01");  // ��������� ����� ������ ���� "2024-12-01"
}

// ���� ��� ������ printHistory
TEST(TransactionHistoryTest, PrintHistory) {
    Account account(1, 1000.0);
    Transaction transaction1(&account, "���������", 500.0, "2024-12-01");
    Transaction transaction2(&account, "�����", 200.0, "2024-12-02");

    TransactionHistory history;
    history.addTransaction(&transaction1);
    history.addTransaction(&transaction2);

    testing::internal::CaptureStdout();
    history.printHistory();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("������� � ������� 500"), std::string::npos);  // �������� �� ������� ������� ��������
    EXPECT_NE(output.find("������� � ������� 200"), std::string::npos);  // �������� �� ������� ������� ��������
    EXPECT_NE(output.find("�� ������ 2024-12-01"), std::string::npos);  // �������� �� ������������ ���� ������� ��������
    EXPECT_NE(output.find("�� ������ 2024-12-02"), std::string::npos);  // �������� �� ������������ ���� ������� ��������
}

// ���� ��� ������ getTransactions (���������� ��� ����������)
TEST(TransactionHistoryTest, GetTransactions) {
    Account account(1, 1000.0);
    Transaction transaction1(&account, "���������", 500.0, "2024-12-01");
    Transaction transaction2(&account, "�����", 200.0, "2024-12-02");

    TransactionHistory history;
    history.addTransaction(&transaction1);
    history.addTransaction(&transaction2);

    const auto& transactions = history.getTransactions();
    EXPECT_EQ(transactions.size(), 2);  // ������ ���� ��� ����������
    EXPECT_EQ(transactions[0]->getAmount(), 500.0);  // �������� ����� ������ ����������
    EXPECT_EQ(transactions[1]->getAmount(), 200.0);  // �������� ����� ������ ����������
}

// ���� �� ������ ������� ����������
TEST(TransactionHistoryTest, EmptyHistory) {
    TransactionHistory history;
    const auto& transactions = history.getTransactions();

    EXPECT_EQ(transactions.size(), 0);  // ������� ���������� ������ ���� �����
}

// ���� ��� ������ printHistory ��� ���������� ����������
TEST(TransactionHistoryTest, PrintEmptyHistory) {
    TransactionHistory history;

    testing::internal::CaptureStdout();
    history.printHistory();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "");  // ��� ������ ������� ������ �� ���������
}
