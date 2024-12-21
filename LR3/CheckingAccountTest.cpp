#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/CheckingAccount.h"
#include "../ppois33/CheckingAccount.cpp"
#include <iostream>
#include <sstream>

// ������������ ������ CheckingAccount

// ���� ��� ������������ � �������������
TEST(CheckingAccountTest, ConstructorAndInitialization) {
    CheckingAccount account(1, 1000.0, 500.0);

    EXPECT_EQ(account.getId(), 1);  // �������� ID �����
    EXPECT_EQ(account.getBalance(), 1000.0);  // �������� ���������� �������
    EXPECT_EQ(account.getOverdraftLimit(), 500.0);  // �������� ������ ����������
}

// ���� ��� ������ withdraw (������ ������� � ����������� ������)
TEST(CheckingAccountTest, WithdrawExceedsLimit) {
    CheckingAccount account(1, 1000.0, 500.0);  // ������ 1000, ����� ���������� 500

    // �������������� ����� � ��������� �����, ����� ��������� ���������
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // ������������� std::cout

    account.withdraw(1600.0);  // ������� 1600 (������ + ����� ����������)

    // ���������, ��� ����� ��������� � ���������
    EXPECT_EQ(output.str(), "������������ ������� ���� �������� ����� ����!\n");

    // ��������������� ����� ������
    std::cout.rdbuf(originalBuffer);

    // ���������, ��� ������ �� ���������
    EXPECT_EQ(account.getBalance(), 1000.0);
}

// ���� ��� ������ getOverdraftLimit
TEST(CheckingAccountTest, GetOverdraftLimit) {
    CheckingAccount account(1, 1000.0, 500.0);

    EXPECT_EQ(account.getOverdraftLimit(), 500.0);  // �������� ������������ ������ ����������
}

// ���� ��� ������ withdraw � ������������� ������� ����������
TEST(CheckingAccountTest, WithdrawWithNegativeOverdraftLimit) {
    CheckingAccount account(1, 1000.0, -500.0);  // ����� ���������� �������������

    // �������������� ����� � ��������� �����, ����� ��������� ���������
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // ������������� std::cout

    account.withdraw(1200.0);  // ������� 1200, ��� ������ ����������

    // ���������, ��� ����� ��������� � ���������
    EXPECT_EQ(output.str(), "������������ ������� ���� �������� ����� ����!\n");

    // ��������������� ����� ������
    std::cout.rdbuf(originalBuffer);

    // ���������, ��� ������ �� ���������
    EXPECT_EQ(account.getBalance(), 1000.0);
}
