#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/Loan.h"
#include "../ppois33/Loan.cpp"
#include <sstream>

// ������������ ������ Loan

// ���� ��� ������������ � �������������
TEST(LoanTest, ConstructorAndInitialization) {
    Loan loan(10000.0, 5.0, "2025-12-31");  // ������� ������ �� 10000 � ���������� ������� 5.0 � ����� ��������� 2025-12-31

    EXPECT_EQ(loan.getAmount(), 10000.0);  // �������� ��������� ����� �������
    EXPECT_EQ(loan.getInterestRate(), 5.0);  // �������� ���������� ������
    EXPECT_EQ(loan.getDueDate(), "2025-12-31");  // �������� ���� ���������
}

// ���� ��� ������ approveLoan (��������� �������)
TEST(LoanTest, ApproveLoan) {
    Loan loan(10000.0, 5.0, "2025-12-31");

    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // ������������� std::cout

    loan.approveLoan();  // �������� ������

    // ���������, ��� ����� ��������� � ���������
    EXPECT_EQ(output.str(), "������ �������.\n");

    // ��������������� ����� ������
    std::cout.rdbuf(originalBuffer);
}

// ���� ��� ������ payInstallment (������ ����� ������� ����� ��� ���������)
TEST(LoanTest, PayInstallmentAfterApproval) {
    Loan loan(10000.0, 5.0, "2025-12-31");
    loan.approveLoan();  // �������� ������

    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // ������������� std::cout

    loan.payInstallment(2000.0);  // ������ 2000

    // ��������� �����
    EXPECT_EQ(output.str(), "���������� ����� �������: 2000, ���������� �������������: 8000\n");

    // ��������������� ����� ������
    std::cout.rdbuf(originalBuffer);

    // ���������, ��� ���������� ����� ������� �����������
    EXPECT_EQ(loan.getAmount(), 8000.0);  // ������� ����� ������ ������ ���� 8000
}

// ���� ��� ������ payInstallment (������� ������ �� ��������� �������)
TEST(LoanTest, PayInstallmentBeforeApproval) {
    Loan loan(10000.0, 5.0, "2025-12-31");

    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());  // ������������� std::cout

    loan.payInstallment(2000.0);  // ������ �� ��������� �������

    // ��������� ����� ������
    EXPECT_EQ(output.str(), "������ ��� �� �������.\n");

    // ��������������� ����� ������
    std::cout.rdbuf(originalBuffer);

    // ���������, ��� ���������� ����� ������� �� ����������
    EXPECT_EQ(loan.getAmount(), 10000.0);  // ������� ������ �������� 10000
}

// ���� ��� ������ getAmount (��������� ���������� ����� �������)
TEST(LoanTest, GetAmount) {
    Loan loan(10000.0, 5.0, "2025-12-31");
    loan.approveLoan();  // �������� ������

    loan.payInstallment(2000.0);  // ������ 2000

    EXPECT_EQ(loan.getAmount(), 8000.0);  // ������� ����� ������ ������ ���� 8000
}

// ���� ��� ������ getInterestRate (��������� ���������� ������)
TEST(LoanTest, GetInterestRate) {
    Loan loan(10000.0, 5.0, "2025-12-31");

    EXPECT_EQ(loan.getInterestRate(), 5.0);  // ���������� ������ ������ ���� 5.0
}

// ���� ��� ������ getDueDate (��������� ���� ���������)
TEST(LoanTest, GetDueDate) {
    Loan loan(10000.0, 5.0, "2025-12-31");

    EXPECT_EQ(loan.getDueDate(), "2025-12-31");  // ���� ��������� ������ ���� 2025-12-31
}
