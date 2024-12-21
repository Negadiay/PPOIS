#include "gtest/gtest.h"
#include "pch.h"    
#include "../ppois33/ATM.h"
#include "../ppois33/ATM.cpp"
#include "../ppois33/Account.h"
#include <iostream>

// ������������ ������ ATM

// ���� ��� ������������ ATM
TEST(ATMTest, Constructor) {
    ATM atm(1, "Downtown");
    EXPECT_EQ(atm.getAtmId(), 1);
    EXPECT_EQ(atm.getLocation(), "Downtown");
}

// ���� ��� �������� ����� ��������
TEST(ATMTest, Deposit) {
    Account account(1, 100.0);  // ��������� ������ 100
    ATM atm(1, "Downtown");

    atm.deposit(&account, 50.0);  // ������� 50
    EXPECT_EQ(account.getBalance(), 150.0);  // ������ ������ ���� 150
}

// ���� ��� ������ ������� ����� �������� � ����������� ��������
TEST(ATMTest, Withdraw) {
    Account account(1, 200.0);  // ��������� ������ 200
    ATM atm(1, "Downtown");

    atm.withdraw(&account, 50.0);  // ������ 50
    EXPECT_EQ(account.getBalance(), 150.0);  // ������ ������ ���� 150
}

// ���� ��� ������ ������� ����� �������� � ������������� ��������
TEST(ATMTest, WithdrawInsufficientFunds) {
    Account account(1, 100.0);  // ��������� ������ 100
    ATM atm(1, "Downtown");

    atm.withdraw(&account, 150.0);  // ������ 150 �� ������ ���� ���������
    EXPECT_EQ(account.getBalance(), 100.0);  // ������ �������� 100
}

// ���� ��� ���������� �������� � ����������
TEST(ATMTest, MultipleTransactions) {
    Account account(1, 100.0);  // ��������� ������ 100
    ATM atm(1, "Downtown");

    atm.deposit(&account, 50.0);  // ������� 50
    EXPECT_EQ(account.getBalance(), 150.0);

    atm.withdraw(&account, 30.0);  // ������ 30
    EXPECT_EQ(account.getBalance(), 120.0);

    atm.deposit(&account, 100.0);  // ������� 100
    EXPECT_EQ(account.getBalance(), 220.0);

    atm.withdraw(&account, 50.0);  // ������ 50
    EXPECT_EQ(account.getBalance(), 170.0);
}
