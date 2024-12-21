#pragma once

#include <string>
#include "Account.h"

class ATM {
private:
    int atmId;
    std::string location;

public:
    ATM(int atmId, const std::string& location);
    void withdraw(Account* account, double amount);
    void deposit(Account* account, double amount);
    int getAtmId() const;
    const std::string& getLocation() const;
};
