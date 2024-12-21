#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/CreditCard.h"
#include "../ppois33/CreditCard.cpp"
#include "../ppois33/Account.h"
#include <iostream>
#include <sstream>

// ������������ ������ CreditCard

// ���� ��� ������������ � �������������
TEST(CreditCardTest, ConstructorAndInitialization) {
    Account account(1, 1000.0);  // ������� ������� � �������� 1000
    CreditCard card(1234567890, 5000.0, &account);  // ����� � ������� 5000

    EXPECT_EQ(card.getCardNumber(), 1234567890);  // �������� ������ �����
    EXPECT_EQ(card.getCreditLimit(), 5000.0);  // �������� ���������� ������
    EXPECT_EQ(card.getBalance(), 0.0);  // ������ ����� ������ ���� 0
}

// ���� ��� ������ charge (�������� ������� � �������� ������)
TEST(CreditCardTest, ChargeWithinLimit) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);

    // �������������� ����� � ��������� �����, ����� ��������� ���������
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // ������������� std::cout

    card.charge(2000.0);  // ������� 2000, ��� ������ ������ 5000

    // ���������, ��� ����� ��������� � ���������
    EXPECT_EQ(output.str(), "���������� 2000 �� ����� 1234567890\n");

    // ��������������� ����� ������
    std::cout.rdbuf(originalBuffer);

    // ��������� ������ ����� ����� ��������
    EXPECT_EQ(card.getBalance(), 2000.0);
}

// ���� ��� ������ charge (�������� �������, ����������� �����)
TEST(CreditCardTest, ChargeExceedsLimit) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);

    // �������������� ����� � ��������� �����, ����� ��������� ���������
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // ������������� std::cout

    card.charge(6000.0);  // ������� 6000, ��� ��������� ����� 5000

    // ���������, ��� ����� ��������� � ���������
    EXPECT_EQ(output.str(), "����� ��������� ��������� �����!\n");

    // ��������������� ����� ������
    std::cout.rdbuf(originalBuffer);

    // ���������, ��� ������ ����� �� ���������
    EXPECT_EQ(card.getBalance(), 0.0);
}

// ���� ��� ������ makePayment (������ ������� � �����)
TEST(CreditCardTest, MakePayment) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);

    card.charge(2000.0);  // ������� 2000
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // ������������� std::cout

    card.makePayment(1000.0);  // ������ 1000

    // ���������, ��� ����� ��������� � ���������
    EXPECT_EQ(output.str(), "������ 1000 ���� ��������� � ����� 1234567890\n");

    // ��������������� ����� ������
    std::cout.rdbuf(originalBuffer);

    // ���������, ��� ������ ����� ����� ������ ����������
    EXPECT_EQ(card.getBalance(), 1000.0);  // 2000 - 1000 = 1000
}

// ���� ��� ������ getBalance (��������� �������� ������� �����)
TEST(CreditCardTest, GetBalance) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);

    card.charge(1000.0);  // ������� 1000

    EXPECT_EQ(card.getBalance(), 1000.0);  // ������ ����� ����� ������ ������ ���� 1000
}

// ���� ��� ������ getCreditLimit (��������� ������ �����)
TEST(CreditCardTest, GetCreditLimit) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);

    EXPECT_EQ(card.getCreditLimit(), 5000.0);  // ����� ����� ������ ���� 5000
}

// ���� ��� ������ getCardNumber (��������� ������ �����)
TEST(CreditCardTest, GetCardNumber) {
    Account account(1, 1000.0);
    CreditCard card(1234567890, 5000.0, &account);

    EXPECT_EQ(card.getCardNumber(), 1234567890);  // ����� ����� ������ ���� 1234567890
}
