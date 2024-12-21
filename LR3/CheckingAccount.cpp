#include "CheckingAccount.h"
#include <iostream>

CheckingAccount::CheckingAccount(int id, double balance, double overdraftLimit)
    : Account(id, balance), overdraftLimit(overdraftLimit) {}

void CheckingAccount::withdraw(double amount) {
    if (getBalance() + overdraftLimit >= amount) {
        Account::withdraw(amount);
    }
    else {
        std::cout << "Ќедостаточно средств либо превышен лимит трат!" << std::endl;
    }
}

double CheckingAccount::getOverdraftLimit() const {
    return overdraftLimit;
}
