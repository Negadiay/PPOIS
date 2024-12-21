#include "Mortgage.h"
#include <iostream>

Mortgage::Mortgage(double amount, double interestRate, const std::string& dueDate, double propertyValue, double downPayment)
    : Loan(amount, interestRate, dueDate), propertyValue(propertyValue), downPayment(downPayment) {}

double Mortgage::getPropertyValue() const {
    return propertyValue;
}

double Mortgage::getDownPayment() const {
    return downPayment;
}
