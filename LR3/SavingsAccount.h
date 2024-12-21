#pragma once

#include <string>
#include "Account.h"

class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int id, double balance, double interestRate);
    double getInterestRate() const;
};
