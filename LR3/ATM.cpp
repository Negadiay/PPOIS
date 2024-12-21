#include "ATM.h"
#include "Account.h"
#include <iostream>

ATM::ATM(int atmId, const std::string& location) : atmId(atmId), location(location) {}

void ATM::withdraw(Account* account, double amount) {
    account->withdraw(amount);
}

void ATM::deposit(Account* account, double amount) {
    account->deposit(amount);
}

int ATM::getAtmId() const {
    return atmId;
}

const std::string& ATM::getLocation() const {
    return location;
}
