#pragma once

#include <string>
#include "Account.h"

class CreditCard {
private:
    int cardNumber;
    double creditLimit;
    double balance;
    Account* associatedAccount;

public:
    CreditCard(int cardNumber, double creditLimit, Account* associatedAccount);
    void charge(double amount);
    void makePayment(double amount);
    double getBalance() const;
    double getCreditLimit() const;
    int getCardNumber() const;
};
