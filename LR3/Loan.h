#pragma once

#include <string>
#include "Customer.h"

class Loan {
private:
    double amount;
    double interestRate;
    std::string dueDate;
    bool isApproved;

public:
    Loan(double amount, double interestRate, const std::string& dueDate);
    void approveLoan();
    void payInstallment(double amount);
    double getAmount() const;
    double getInterestRate() const;
    const std::string& getDueDate() const;
};
