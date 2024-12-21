#pragma once

#include <string>
#include "Account.h"

class CheckingAccount : public Account {
private:
    double overdraftLimit;

public:
    CheckingAccount(int id, double balance, double overdraftLimit);
    void withdraw(double amount);
    double getOverdraftLimit() const;
};
