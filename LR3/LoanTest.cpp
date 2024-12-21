#include "gtest/gtest.h"
#include "pch.h"
#include "../ppois33/Loan.h"
#include "../ppois33/Loan.cpp"
#include <sstream>

TEST(LoanTest, ConstructorAndInitialization) {
    Loan loan(10000.0, 5.0, "2025-12-31");
    EXPECT_EQ(loan.getAmount(), 10000.0);
    EXPECT_EQ(loan.getInterestRate(), 5.0);
    EXPECT_EQ(loan.getDueDate(), "2025-12-31");
}

TEST(LoanTest, ApproveLoan) {
    Loan loan(10000.0, 5.0, "2025-12-31");
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());
    loan.approveLoan();
    EXPECT_EQ(output.str(), "Кредит одобрен.\n");
    std::cout.rdbuf(originalBuffer);
}

TEST(LoanTest, PayInstallmentAfterApproval) {
    Loan loan(10000.0, 5.0, "2025-12-31");
    loan.approveLoan();
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());
    loan.payInstallment(2000.0);
    EXPECT_EQ(output.str(), "Оплаченная сумма кредита: 2000, оставшаяся задолженность: 8000\n");
    std::cout.rdbuf(originalBuffer);
    EXPECT_EQ(loan.getAmount(), 8000.0);
}

TEST(LoanTest, PayInstallmentBeforeApproval) {
    Loan loan(10000.0, 5.0, "2025-12-31");
    std::stringstream output;
    std::streambuf* originalBuffer = std::cout.rdbuf(output.rdbuf());
    loan.payInstallment(2000.0);
    EXPECT_EQ(output.str(), "Кредит еще не одобрен.\n");
    std::cout.rdbuf(originalBuffer);
    EXPECT_EQ(loan.getAmount(), 10000.0);
}

TEST(LoanTest, GetAmount) {
    Loan loan(10000.0, 5.0, "2025-12-31");
    loan.approveLoan();
    loan.payInstallment(2000.0);
    EXPECT_EQ(loan.getAmount(), 8000.0);
}

TEST(LoanTest, GetInterestRate) {
    Loan loan(10000.0, 5.0, "2025-12-31");
    EXPECT_EQ(loan.getInterestRate(), 5.0);
}

TEST(LoanTest, GetDueDate) {
    Loan loan(10000.0, 5.0, "2025-12-31");
    EXPECT_EQ(loan.getDueDate(), "2025-12-31");
}
