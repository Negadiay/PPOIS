#pragma once

#include <string>
#include "Loan.h"

class Mortgage : public Loan {
private:
    double propertyValue;
    double downPayment;

public:
    Mortgage(double amount, double interestRate, const std::string& dueDate, double propertyValue, double downPayment);
    double getPropertyValue() const;
    double getDownPayment() const;
};
