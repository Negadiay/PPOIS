#include "CreditCard.h"
#include <iostream>

CreditCard::CreditCard(int cardNumber, double creditLimit, Account* associatedAccount)
    : cardNumber(cardNumber), creditLimit(creditLimit), balance(0), associatedAccount(associatedAccount) {}

void CreditCard::charge(double amount) {
    if (balance + amount <= creditLimit) {
        balance += amount;
        std::cout << "Переведено " << amount << " на карту " << cardNumber << std::endl;
    }
    else {
        std::cout << "Сумма превышает кредитный лимит!" << std::endl;
    }
}

void CreditCard::makePayment(double amount) {
    balance -= amount;
    std::cout << "Оплата " << amount << " была проведена с карты " << cardNumber << std::endl;
}

double CreditCard::getBalance() const {
    return balance;
}

double CreditCard::getCreditLimit() const {
    return creditLimit;
}

int CreditCard::getCardNumber() const {
    return cardNumber;
}
