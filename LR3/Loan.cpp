#include "Loan.h"
#include <iostream>

Loan::Loan(double amount, double interestRate, const std::string& dueDate)
    : amount(amount), interestRate(interestRate), dueDate(dueDate), isApproved(false) {}

void Loan::approveLoan() {
    isApproved = true;
    std::cout << "������ �������." << std::endl;
}

void Loan::payInstallment(double amount) {
    if (isApproved) {
        this->amount -= amount;
        std::cout << "���������� ����� �������: " << amount << ", ���������� �������������: " << this->amount << std::endl;
    }
    else {
        std::cout << "������ ��� �� �������." << std::endl;
    }
}

double Loan::getAmount() const {
    return amount;
}

double Loan::getInterestRate() const {
    return interestRate;
}

const std::string& Loan::getDueDate() const {
    return dueDate;
}
