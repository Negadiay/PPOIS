#include "CreditCard.h"
#include <iostream>

CreditCard::CreditCard(int cardNumber, double creditLimit, Account* associatedAccount)
    : cardNumber(cardNumber), creditLimit(creditLimit), balance(0), associatedAccount(associatedAccount) {}

void CreditCard::charge(double amount) {
    if (balance + amount <= creditLimit) {
        balance += amount;
        std::cout << "���������� " << amount << " �� ����� " << cardNumber << std::endl;
    }
    else {
        std::cout << "����� ��������� ��������� �����!" << std::endl;
    }
}

void CreditCard::makePayment(double amount) {
    balance -= amount;
    std::cout << "������ " << amount << " ���� ��������� � ����� " << cardNumber << std::endl;
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
