#include "SavingsAccount.h"
#include <iostream>

SavingsAccount::SavingsAccount(int id, double balance, double interestRate)
    : Account(id, balance), interestRate(interestRate) {}

double SavingsAccount::getInterestRate() const {
    return interestRate;
}
